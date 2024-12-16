#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
// Compile
// gcc 4.22.c -lm

// Range of the space contain the circle and all the point
#define RANGE 5
// Circle properties
#define RADIUS 5
#define H 0 // x
#define K 0 // y

// Function to check if the point is inside, on, or outside the circle
bool check_point_in_circle(double x, double y)
{
    double distance_squared = pow(x - H, 2) + pow(y - K, 2);
    double radius_squared = RADIUS * RADIUS;

    if (distance_squared <= radius_squared)
    {
        return true;
    }
    else
    {
        return false;
    }
}

typedef struct
{
    double x;
    double y;
} point;

double totalInCircle = 0;

/* generate a random floating point number from min to max */
double randFrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

// Function to Create random point and count the point that in the circle
void *generatePointAndCount(void *param)
{
    int *total = (int *)param;
    for (int i = 0; i < *total; i++) {
        point *p = (point *)malloc(sizeof(point));
        if (p == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        // Generate random values for x and y in the range -5 to 5
        p->x = randFrom(-RANGE, RANGE);
        p->y = randFrom(-RANGE, RANGE);
        
        if (check_point_in_circle(p->x, p->y))
        {
            totalInCircle++;
        }

        free(p);
    }

    pthread_exit(0);
}

int main()
{
    int total;
    printf("Enter a total of point: ");
    scanf("%d", &total);

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, generatePointAndCount, &total);

    pthread_join(tid, NULL);

    double pi = 4 * totalInCircle / total;

    printf("totalInCircle: %lf\n", totalInCircle);
    printf("Result: %lf\n", pi);
    return 0;
}
