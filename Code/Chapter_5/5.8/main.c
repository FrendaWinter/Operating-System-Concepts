#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

// Shared variables for Peterson's solution
bool flag[2] = {false, false};
int turn = 0;

// Function for thread 1
void *thread1(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        // Entry section
        flag[0] = true;
        turn = 1;
        while (flag[1] && turn == 1)
            ;

        // Critical section
        printf("Thread 1: Entering critical section (iteration %d)\n", i + 1);
        sleep(1); // Simulate work in critical section
        printf("Thread 1: Exiting critical section (iteration %d)\n", i + 1);

        // Exit section
        flag[0] = false;

        // Remainder section
        printf("Thread 1: Doing non-critical work (iteration %d)\n", i + 1);
        sleep(1);
    }
    return NULL;
}

// Function for thread 2
void *thread2(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        // Entry section
        flag[1] = true;
        turn = 0;
        while (flag[0] && turn == 0)
            ;

        // Critical section
        printf("Thread 2: Entering critical section (iteration %d)\n", i + 1);
        sleep(1); // Simulate work in critical section
        printf("Thread 2: Exiting critical section (iteration %d)\n", i + 1);

        // Exit section
        flag[1] = false;

        // Remainder section
        printf("Thread 2: Doing non-critical work (iteration %d)\n", i + 1);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have completed.\n");
    return 0;
}
