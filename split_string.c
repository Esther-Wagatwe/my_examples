#include <stdio.h>
#include <string.h>

int main()
{
	char string[] = "My name is Esther";
	char *delim = " ";

	while (delim)
	{
		printf("%s\n", string);
	}
	return (0);
}
