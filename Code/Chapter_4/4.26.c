#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
long long int Fibonacci[102];

void *runner(void *param) {
    int *num = (int *)param;

    for (int i = 0; i < *num; i++) {
        Fibonacci[i + 2] = Fibonacci[i + 1] + Fibonacci[i];
    }
    pthread_exit(0);
}

int main()
{
    int num;
    printf("Enter a number of Fibonacci (<100): ");
    scanf("%d", &num);

    if (num > 100 || num < 1) {
        printf("Number not in range\n");
        exit(1);
    }

    Fibonacci[0] = 0;
    Fibonacci[1] = 1;

    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, &num);
    pthread_join(tid, NULL);

    for (int i = 2; i < num + 2; i++)
    {
        printf("%d ", Fibonacci[i]);
    }
    printf("\n");
    return 0;
}
