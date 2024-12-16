#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>

int value = 0;
void *runner(void *param); /* the thread */
int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pid = fork();
    if (pid == 0)
    { /* child process */
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("CHILD: value = %d\n", value); /* LINE C */
    }
    else if (pid > 0)
    { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d\n", value); /* LINE P */
    }
}

void *runner(void *param)
{
    value = 5;
    pthread_exit(0);
}