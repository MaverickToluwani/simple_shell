#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define SIZE 1024

void execute_func(char **commmandList, char **env);
char **sizealloc(char *buffer);

#endif
