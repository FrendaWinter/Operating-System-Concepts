#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int N = 100000;

    int a[N], b[N], c[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = 0;
        b[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        a[i] += 1 * i;
    }
    /* sequential code */

// #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        b[i] += 2 * i;
    }

// #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        c[i] += b[i] - a[i] + 1;
    }

// #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\nDone\n");
    return 0;
}