#include "main.h"

#define SIZE 1024

/**
 * main - executes arguments passed to it
 * @argc: Counts the number of argument passed after the executable file
 * @argv: Array of pointers composed arguments passed after the executable file 
 * env: A pointer to a pointer to a character of environment variables
 * Return: Success (0)
 */
int main(int argc, char *argv[], char **env)
{
	char *buffer = NULL;
	char **command;
	size_t bufsize = 0;
	size_t characters;
	char *token;
	pid_t child;

	while(1)
	{
		int i = 0;

		printf("cisfun ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			perror("Failure!");
			exit(EXIT_FAILURE);
		}
		if (buffer[characters - 1] == '\n')
		{
			buffer[characters - 1] = '\0';
		}
		command = (char **)malloc(SIZE * sizeof(char *));
		if (command == NULL)
		{
			perror("could not assign memory");
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
		child = fork();
		if (child == -1)
		{
			perror("Error");
			free(buffer);
			free(command);
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			if (strcmp(command[0], "ls") == 0)
				command[0] = "/bin/ls";

			if (execve(command[0], command, env) == -1);
			{
				perror("Error: execution failed");
				/*free(buffer);
				free(command);
				kill(getpid(), SIGTERM);*/
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
			free(command);
		}
	
	}
	free(buffer);
	return(0);
}
