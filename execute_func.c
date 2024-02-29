#include "main.h"
/**
 * execute_func - Executes executable files
 * @command: array of strings passed to the execve
 * @env: Environmental variable
 */

void execute_func(char **command, char **env)
{
	if (strcmp(command[0], "ls") == 0)
		command[0] = "/bin/ls";
	if (execve(command[0], command, env) == -1)
	{
		perror("execve");
		free(command);
		exit(EXIT_FAILURE);
	}
}
