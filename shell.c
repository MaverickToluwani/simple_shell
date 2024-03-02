#include "main.h"

/**
 * main - Executes argumemts
 * @argc: Counts the number of arguments after executable file
 * @argv: Array of pointers composed of arguments passed after executable file
 * @env: Pointer to an array of environment variables
 * Return: 0(Success)
 */
extern char **environ;

int main(void)
{
	pid_t child_p;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t num_counter;
	char **command;
	char **env = environ;

	while (1)
	{
		printf("#cisfun$ ");
		num_counter = getline(&buffer, &bufsize, stdin);
		if (num_counter == EOF)
		{
			perror("getline");
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if ((buffer[num_counter - 1]) == '\n')
			buffer[num_counter - 1] = '\0';

	       	command = sizealloc(buffer);
		child_p = fork();
		if (child_p == -1)
		{
			perror("Error process not created");
			free(buffer);
			free(command);
			return (1);
		}
		if (child_p == 0)
			execute_func(command,env);
		else
		{
			wait(NULL);
		}

	}
	free(buffer);
	return (0);
}
