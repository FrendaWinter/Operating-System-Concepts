#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 8192
int intLength(int number)
{
    if (number == 0)
        return 1; // Special case for 0
    if (number < 0)
        number = -number; // Handle negative numbers

    int length = 0;
    while (number > 0)
    {
        length++;
        number /= 10; // Remove the last digit
    }
    return length;
}

int main()
{
    pid_t pid;
    pid = fork();

    // Collatz conjecture
    const char *name = "Collatz";
    if (pid == 0)
    {
        int num;
        printf("Enter a number (Don't input a too big number): ");
        scanf("%d", &num);

        /* shared memory file descriptor */
        int shm_fd;
        /* pointer to shared memory obect */
        void *ptr;
        /* create the shared memory object */
        shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
        /* configure the size of the shared memory object */
        ftruncate(shm_fd, SIZE);
        /* memory map the shared memory object */
        ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
                // char buffer[20];
                // sprintf(buffer, "%d", num);
                sprintf(ptr, "%d ", num);
                ptr += intLength(num) + 1;
                continue;
            }

            if (num % 2 == 1)
            {
                num = 3 * num + 1;
                // char buffer[20];
                // sprintf(buffer, "%d", num);
                sprintf(ptr, "%d ", num);
                ptr += intLength(num) + 1;
                continue;
            }
        }
        printf("Child process done.\n");
        printf("\n");
        return 0;
    }
    else if (pid > 0)
    {
        wait(NULL);
        int shm_fd;
        /* pointer to shared memory obect */
        void *ptr;
        /* open the shared memory object */
        shm_fd = shm_open(name, O_RDONLY, 0666);
        /* memory map the shared memory object */
        ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        /* read from the shared memory object */
        printf("%s\n", (char *)ptr);
        /* remove the shared memory object */
        shm_unlink(name);
        return 0;
    }
}