#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int should_run = 1;
    while (should_run)
    {
        printf("osh> ");
        fflush(stdout);

        char line[256];
        // Read user input
        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            continue;
        }

        printf("%s", line);
    }
    return 0;
}