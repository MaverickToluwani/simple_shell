#include "main.h"

/**
 *
 */
void execute_func(char **commandList, char **env)
{
	if (execve(commandList[0], commandList, env) == -1)
	{
		perror("execve");
		free(commandList);
		exit(EXIT_FAILURE);
	}
}
