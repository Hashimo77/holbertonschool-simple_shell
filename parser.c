#include "shell.h"

#define MAX_ARGS 64

/**
 * parse_command - Split a line into arguments
 * @line: Input command line
 *
 * Return: NULL-terminated array of arguments (static limit)
 */
char **parse_command(char *line)
{
	static char *argv[MAX_ARGS];
	char *token;
	int argc = 0;
	int i;

	for (i = 0; i < MAX_ARGS; i++)
		argv[i] = NULL;

	token = strtok(line, " \t");
	while (token && argc < MAX_ARGS - 1)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t");
	}

	argv[argc] = NULL;
	return (argv);
}
