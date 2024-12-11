#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        // Collatz conjecture
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);

        while(num != 1) {
            if (num %2 == 0) {
                num = num / 2;
                printf("%d ", num);
                continue;
            } 
                
            if (num % 2 == 1) {
                num = 3 * num + 1;
                printf("%d ", num);
                continue;
            }   
        }
        return 0;
    }
    else if (pid > 0)
    {
        wait(NULL);
        return 0;
    }
}