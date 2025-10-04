#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int _strcmp(char *s1, char *s2);
void execute_command(char *command);

#endif
