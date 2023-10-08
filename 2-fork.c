#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid;

    printf("Before fork\n");
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error in fork");
        return 1;
    }

    if (child_pid == 0)
    {
        // This code block executes in the child process
        printf("Child process: PID is %d\n", getpid());
    }
    else
    {
        // This code block executes in the parent process
        printf("Parent process: PID is %d, child's PID is %d\n", getpid(), child_pid);
    }

    return 0;
}

