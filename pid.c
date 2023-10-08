#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t process_id, parentprocess_id;

	process_id = getpid();
	parentprocess_id = getppid();

	printf("My process id is %u\n", process_id);
	printf("My parentprocess id is %u\n", parentprocess_id);
	return (0);
}

