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
        fork();
    }

    fork();
    printf("pid = %d", getpid());
    return 0;
}