#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
	pid_t child_process;
	char *line = NULL, *token, *delim = " ";
	size_t len = 0;
	ssize_t read;
	int fp,status;

	while (1)
	{
		printf("($) ");
		while (read = getline(&line, &len, stdin) == -1)
		{
			if (feof(stdin))
			{
				break;/*exit EOF loop*/
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}
		/* Remove newline character at the end*/
        	if (line[read - 1] == '\n')
        	{
			line[read - 1] = '\0';
        	}
		/*create a child process*/
		child_process = fork();
		if (child_process == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		if (child_process == 0)
		{
			token = strtok(line, delim);
			if (token == NULL)
			{
				/*No command provided, just continue to the next prompt*/
				exit(EXIT_SUCCESS);
			}
			// Get the next token
  	          	token = strtok(NULL, delim);
			 /*execute the command inside the chil    dprocess*/
			execve(token, &token, NULL);
				/*print error incase execve fails*/
				perror("Execve error");
				exit(EXIT_FAILURE);
			}
			else
			{
				/*Wait for the child process to finish*/
				wait(&status);
			}
		
		printf("Shell exiting...\n");
		free(line);
	}
	
	return (0);
}
