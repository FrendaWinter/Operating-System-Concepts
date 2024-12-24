#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of the command

char **history = NULL;
int historyCount = 0;

int main(void)
{
    char line[MAX_LINE + 1]; // Buffer to hold the command
    int should_run = 1;      // Flag to keep the shell running

    while (should_run)
    {
        printf("osh> "); // Prompt
        fflush(stdout);

        // Read user input
        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            perror("Error reading input");
            continue;
        }

        // Remove newline character from the input
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "exit") == 0) // Exit condition
        {
            should_run = 0;
            continue;
        }

        // Create a pipe for communication between parent and child
        int pipefd[2];
        if (pipe(pipefd) == -1)
        {
            perror("Pipe failed");
            continue;
        }

        pid_t pid = fork(); // Create a child process
        if (pid < 0)
        {
            perror("Fork failed");
            close(pipefd[0]);
            close(pipefd[1]);
            continue;
        }
        history[historyCount] = line;
        historyCount++;
        if (pid == 0) // Child process
        {
            close(pipefd[0]);               // Close unused read end
            dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
            dup2(pipefd[1], STDERR_FILENO); // Redirect stderr to pipe write end
            close(pipefd[1]);

            char *args[MAX_LINE / 2 + 1]; // Tokenize the command
            int i = 0;
            char *token = strtok(line, " ");
            while (token != NULL && i < (MAX_LINE / 2))
            {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;


            execvp(args[0], args); // Execute the command
            perror("Exec failed"); // If execvp fails
            exit(1);
        }
        else // Parent process
        {
            close(pipefd[1]); // Close unused write end
            char buffer[1024];
            ssize_t bytes_read;

            // Read and output the child's output from the pipe
            while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0)
            {
                buffer[bytes_read] = '\0'; // Null-terminate the buffer
                printf("%s", buffer);
            }

            while (historyCount --> 0)
            {
                printf("%s", history[historyCount]);
            }

            close(pipefd[0]); // Close the read end
            wait(NULL);       // Wait for the child process to finish
        }
    }

    return 0;
}
