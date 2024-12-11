#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MIN_PID 300
#define MAX_PID 5000
#define PID_RANGE (MAX_PID - MIN_PID + 1)

// Bitmap to manage PIDs
static bool *pid_map = NULL;

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
        {                      // Check if the PID is available
            pid_map[i] = true; // Mark the PID as in use
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

    if (pid_map[pid - MIN_PID] == false) {
        printf("This PID not in use. Nothing to release.");
        return;
    }
    
    pid_map[pid - MIN_PID] = false; // Mark the PID as available
}

// Example usage
int main()
{
    if (allocate_map() == -1)
    {
        printf("Failed to initialize PID manager.\n");
        return 1;
    }

    int pid1 = allocate_pid();
    printf("Allocated PID: %d\n", pid1);

    int pid2 = allocate_pid();
    printf("Allocated PID: %d\n", pid2);

    release_pid(pid1);
    printf("Released PID: %d\n", pid1);

    int pid3 = allocate_pid();
    printf("Allocated PID: %d\n", pid3);

    // Free the PID map
    free(pid_map);
    return 0;
}
