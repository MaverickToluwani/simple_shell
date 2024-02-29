#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Succes)
 */
extern char **environ;
int main(void)
{
	ssize_t character;
	size_t bufsize = 0;
	char *buffer = NULL, **command;
	pid_t child;
	char **env = environ;

	while (1)
	{
		printf("#cisfun ");
		character = getline(&buffer, &bufsize, stdin);
		if (character == -1)
		{
			perror("Error!");
			exit(EXIT_FAILURE);
		}
		if (buffer[character - 1] == '\n')
		{
			buffer[character - 1] = '\0';
		}
		command = token_func(buffer);
		child = fork();
		if (child == -1)
		{
			perror("child process not created");
			free(buffer);
			free(command);
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			execute_func(command, env);
		}
		else
		{
			wait(NULL);
			free(command);
		}
	}
	free(buffer);
	return (0);
}
