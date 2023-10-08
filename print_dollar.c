#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        /*Print the "$ " prompt*/
        printf("$ ");
        
        // Use getline to read user input
        read = getline(&line, &len, stdin);

        // Check for EOF (Ctrl+D) or an error
        if (read == -1) {
            if (feof(stdin)) {
                // Exit the loop on EOF (Ctrl+D)
                break;
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }
	printf("%s",line);
    }

    // Free allocated memory
    if (line != NULL) {
        free(line);
    }

    return 0;
}

