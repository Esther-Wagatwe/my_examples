#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;/*stores the exit status of the child process*/

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for me,wait for me\n");
		sleep(3);/* makes the child process sleep for 3 seconds.*/
	}
	else/*In the parent process*/
	{
		/*The parent process waits for the child process to complete*/
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
