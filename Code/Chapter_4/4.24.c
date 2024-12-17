#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num)
{
    if (num <= 1)
        return false; // 0 and 1 are not prime
    if (num == 2)
        return true; // 2 is the smallest prime number

    // Check for factors up to the square root of the number
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false; // Divisible, so not prime
        }
    }
    return true; // No divisors found, so it's prime
}

void *runner(void *param) {
    int *num = (int *)param;

    for (int i = 0; i < *num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    pthread_exit(0);
}

int main()
{
    int num;
    printf("Enter a Number: ");
    scanf("%d", &num);

    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, &num);
    pthread_join(tid, NULL);

    printf("\n");
    return 0;
}
