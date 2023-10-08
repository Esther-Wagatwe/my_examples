#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(void)
{
	pid_t child_pid;
	int i = 0, status;
	char *argv[] = {"/bin/ls", "-l", "/usr", NULL};

	while (i < 5)
	{
		
		child_pid = fork();
		i++;
		if (child_pid == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve("/bin/ls", argv, NULL) != -1)
			{
				sleep(3);
			}
			else
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
