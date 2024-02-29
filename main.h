#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 1024

char **token_func(char *buffer);
void execute_func(char **command, char **env);

#endif
