#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void simple_shell(void);
void execute_command(char **argv);  /* burada char ** olmalıdır */
char **parse_command(char *line);

#endif /* SHELL_H */
