#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MIN_PID 300
#define MAX_PID 5000
#define PID_RANGE (MAX_PID - MIN_PID + 1)

// Bitmap to manage PIDs
static bool *pid_map = NULL;

// Mutex to protect the pid_map
pthread_mutex_t pidMutex;

// Function to initialize the PID map
int allocate_map(void)
{
    pid_map = (bool *)malloc(PID_RANGE * sizeof(bool));
    if (pid_map == NULL)
    {
        return -1; // Unsuccessful allocation
    }

    memset(pid_map, 0, PID_RANGE * sizeof(bool)); // Initialize all PIDs as available
    return 1;                                     // Successful allocation
}

// Function to allocate a PID
int allocate_pid(void)
{
    if (pid_map == NULL)
    {
        return -1; // PID map not initialized
    }

    
    for (int i = 0; i < PID_RANGE; i++)
    {
        if (!pid_map[i])
        {
            pthread_mutex_lock(&pidMutex);
            pid_map[i] = true;
            pthread_mutex_unlock(&pidMutex);
            return MIN_PID + i;
        }
    }
    

    printf("All PIDs are in use.");
    return -1;
}

// Function to release a PID
void release_pid(int pid)
{
    if (pid_map == NULL)
    {
        printf("PID map not initialized.");
        return;
    }
    if (pid < MIN_PID || pid > MAX_PID)
    {
        printf("Invalid PID, please enter PID from range 300-5000.");
        return;
    }

    if (pid_map[pid - MIN_PID] == false)
    {
        printf("This PID not in use. Nothing to release.");
        return;
    }

    pid_map[pid - MIN_PID] = false; // Mark the PID as available
}

void *runner(void *sleepTime)
{
    // Allocate new pid
    int pid1 = allocate_pid();
    printf("Allocated PID: %d\n", pid1);
    // Sleep
    sleep(*(int *)sleepTime);
    // Release pid
    release_pid(pid1);
    printf("Released PID: %d\n", pid1);
    // Exit thread
    pthread_exit(0);
}

int getRandomNumber()
{
    // Generate a random number between 1 and 12
    return (rand() % 12) + 1;
}

// Example usage
int main()
{
    if (allocate_map() == -1)
    {
        printf("Failed to initialize PID manager.\n");
        return 1;
    }

    // Initialize the mutex
    if (pthread_mutex_init(&pidMutex, NULL) != 0)
    {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    pthread_t tid[100];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < 100; i++)
    {
        int *arg = malloc(sizeof(int));
        if (arg == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        *arg = getRandomNumber(); // Pass the thread ID as the argument

        // Create the thread
        if (pthread_create(&tid[i], &attr, runner, arg) != 0)
        {
            fprintf(stderr, "Error creating thread %d\n", i);
            free(arg); // Free memory on error
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 100; i++)
    {
        if (pthread_join(tid[i], NULL) != 0)
        {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 1;
        }
    }

    // Destroy the mutex
    pthread_mutex_destroy(&pidMutex);

    // Free the PID map
    free(pid_map);
    return 0;
}
