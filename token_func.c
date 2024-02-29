#include "main.h"
/**
 * token_func - splits the content of buffer
 * @buffer: An array that stores input from terminal or file stream
 * Return: returns command
 */
char **token_func(char *buffer)
{
	int i = 0;
	char *token;
	char **command = (char **)malloc(SIZE * sizeof(char *));

	if (command == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		command[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	command[i] = NULL;
	return (command);
}
