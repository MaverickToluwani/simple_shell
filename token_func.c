#include "main.h"
/**
 * token_func - splits the content of buffer
 * @buffer: An array that stores input from terminal or file stream
 * @delim: Delimiter to be checked for in the buffer
 * Return: returns command
 */
char **token_func(char *buffer, char *delim)
{
	int i = 0;
	char *token;
	char **command = malloc(SIZE * sizeof(char *));

	if (command == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		command[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;

	return (command);
}
