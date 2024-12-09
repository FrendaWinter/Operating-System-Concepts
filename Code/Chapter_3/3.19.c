#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        // Child process
        printf("Child process done.");
        return 0;
    }
    else if (pid > 0)
    {
        printf("Start sleep.");
        sleep(10);
        printf("Waking, release child process.");
        wait(NULL);
        return 0;
    }
}