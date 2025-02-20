#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        fprintf(stderr, "Usage: %s <divisor> <num1> <num2> <num3> <num4>\n", argv[0]);
        return 1;
    }

    int divisor = atoi(argv[1]);
    for (int i = 2; i < 6; i++)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Fork failed");
            return 1;
        }

        if (pid == 0)
        { // Child process
            execlp("./checker", "checker", argv[1], argv[i], NULL);
            perror("execlp failed");
            exit(1);
        }
        else
        { // Parent process
            printf("Coordinator: forked process with ID %d.\n", pid);
            printf("Coordinator: waiting for process [%d].\n", pid);
            int status;
            waitpid(pid, &status, 0);
            printf("Coordinator: child process %d returned %d.\n", pid, WEXITSTATUS(status));
        }
    }
    printf("Coordinator: exiting.\n");
    return 0;
}