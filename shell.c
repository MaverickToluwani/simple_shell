#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Succes)
 */
extern char **environ;
int main(void)
{
	size_t bufsize = 0;
	char *buffer = NULL, **command;
	pid_t child;
	char **env = environ;
	char *delim = " ";
	int status;
	/*char *pathVar = getenv("PATH");*/

	printf("#cisfun$ ");
	while ((getline(&buffer, &bufsize, stdin)) != EOF)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
		{
			buffer[strlen(buffer) - 1] = '\0';
		}
		if (strcmp(buffer, "exit") == 0)
			break;

		command = token_func(buffer, delim);
		command[0] = converter(command[0]);
		if (access(command[0], X_OK) == 0)
		{
			child = fork();
			if (child == -1)
			{
				perror("child process not created");
				free(buffer);
				free(command);
			}
			else if (child == 0)
				execute_func(command, env);
			else
			{
				wait(&status);
				free(command);
			}
		}
		else
		{
			printf("%s: command not found(this is from shell.c)\n", command[0]);
			free(buffer);
			free(command);
		}
		printf("#cisfun$ ");
	}
	free(buffer);
	return (0);
}
