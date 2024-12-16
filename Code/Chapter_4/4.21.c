#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_NUMBERS 50

// Global variables to store results
double average = 0.0;
int minimum = INT_MAX;
int maximum = INT_MIN;

// Struct to pass data to threads
typedef struct {
    int *numbers;
    int count;
} ThreadData;

// Function to calculate average
void *calculate_average(void *param) {
    ThreadData *data = (ThreadData *)param;
    int sum = 0;
    for (int i = 0; i < data->count; i++) {
        sum += data->numbers[i];
    }
    average = (double)sum / data->count;
    pthread_exit(0);
}

// Function to find the minimum value
void *find_minimum(void *param) {
    ThreadData *data = (ThreadData *)param;
    for (int i = 0; i < data->count; i++) {
        if (data->numbers[i] < minimum) {
            minimum = data->numbers[i];
        }
    }
    pthread_exit(0);
}

// Function to find the maximum value
void *find_maximum(void *param) {
    ThreadData *data = (ThreadData *)param;
    for (int i = 0; i < data->count; i++) {
        if (data->numbers[i] > maximum) {
            maximum = data->numbers[i];
        }
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    int numbers[MAX_NUMBERS];
    int count = 0;

    printf("Enter integers separated by spaces: ");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    // Remove trailing newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    // Parse the input and store integers in the array
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        if (count >= MAX_NUMBERS)
        {
            fprintf(stderr, "Too many numbers, increase MAX_NUMBERS\n");
            return 1;
        }
        numbers[count++] = atoi(token); // Convert token to integer
        token = strtok(NULL, " ");
    }

    // Prepare thread data
    ThreadData data = { numbers, count };

    // Thread IDs
    pthread_t tid_average, tid_minimum, tid_maximum;

    // Create threads
    pthread_create(&tid_average, NULL, calculate_average, &data);
    pthread_create(&tid_minimum, NULL, find_minimum, &data);
    pthread_create(&tid_maximum, NULL, find_maximum, &data);

    // Wait for threads to complete
    pthread_join(tid_average, NULL);
    pthread_join(tid_minimum, NULL);
    pthread_join(tid_maximum, NULL);

    // Print results
    printf("The average value is %.0f\n", average);
    printf("The minimum value is %d\n", minimum);
    printf("The maximum value is %d\n", maximum);

    return 0;
}
