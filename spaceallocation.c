#include "main.h"

/**
 *
 */
char **sizealloc(char *buffer)
{
	char **command = (char **)malloc(SIZE * sizeof(char *));

	if (command == NULL)
	{
		perror("malloc");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	command[0] = buffer;
	command[1] = NULL;

	return (command);
}
