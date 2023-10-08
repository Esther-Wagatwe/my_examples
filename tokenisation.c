#include <stdio.h>
#include <string.h>

int main()
{
	char string[] = "My name is Esther. I am an upcoming software engineer";
	char *token;
	char *delim = " ";

	token = strtok(string, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);/*Use NULL to continue tokenizing*/
	}
	return (0);
}
