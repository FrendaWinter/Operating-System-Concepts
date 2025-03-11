#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CHAIRS 2
#define NUM_STUDENTS 4

// Semaphores and mutex
sem_t ta_sleeping;
sem_t students_waiting;
pthread_mutex_t chairs_mutex;

int waiting_students = 0;

// Teaching Assistant function
void *ta_function(void *arg)
{
    while (1)
    {
        sem_wait(&ta_sleeping); // Wait for a student to wake up the TA

        while (1)
        {
            pthread_mutex_lock(&chairs_mutex);
            if (waiting_students == 0)
            { // No more students waiting
                pthread_mutex_unlock(&chairs_mutex);
                printf("TA is going to sleep...\n");
                break;
            }
            waiting_students--; // Decrement the number of waiting students
            pthread_mutex_unlock(&chairs_mutex);

            printf("TA is helping a student. 1 in help. Remain waiting student: %d\n", waiting_students);
            sleep(rand() % 3 + 1); // Simulate help session
            printf("TA finished helping a student.\n");

            // Signal done. Student got help
            sem_post(&students_waiting);
        }
    }
}

// Student function
void *student_function(void *student_id)
{
    int id = *(int *)student_id;
    while (1)
    {
        printf("Student %d is programming...\n", id);
        sleep(rand() % 5 + 1); // Simulate working

        printf("Student %d needs help and is checking TA.\n", id);

        pthread_mutex_lock(&chairs_mutex);
        if (waiting_students < NUM_CHAIRS)
        { // If there is a free chair
            waiting_students++;
            printf("Student %d is waiting. Students waiting: %d\n", id, waiting_students);
            sem_post(&ta_sleeping); // Wake up the TA if needed
            pthread_mutex_unlock(&chairs_mutex);

            sem_wait(&students_waiting); // Wait for the TA to help
            printf("Student %d got help from the TA. Back to programing\n", id);
        }
        else
        {
            pthread_mutex_unlock(&chairs_mutex);
            printf("Student %d found no empty chairs, will try later.\n", id);
        }
    }
}

int main()
{
    srand(time(NULL));

    pthread_t ta;
    pthread_t students[NUM_STUDENTS];
    int student_ids[NUM_STUDENTS];

    sem_init(&ta_sleeping, 0, 0);
    sem_init(&students_waiting, 0, 0);
    pthread_mutex_init(&chairs_mutex, NULL);

    // Create the TA thread
    pthread_create(&ta, NULL, ta_function, NULL);

    // Create student threads
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        student_ids[i] = i + 1;
        pthread_create(&students[i], NULL, student_function, &student_ids[i]);
    }

    // Join threads (not reached in this infinite loop example)
    pthread_join(ta, NULL);
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        pthread_join(students[i], NULL);
    }

    // Cleanup (not reached in this infinite loop example)
    sem_destroy(&ta_sleeping);
    sem_destroy(&students_waiting);
    pthread_mutex_destroy(&chairs_mutex);

    return 0;
}
