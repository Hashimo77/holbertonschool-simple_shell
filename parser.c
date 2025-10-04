#include "shell.h"

/**
 * parse_command - Split a line into arguments
 * @line: Input command line
 *
 * Return: NULL-terminated array of arguments
 */
char **parse_command(char *line)
{
	char **argv = NULL;
	char *token;
	int argc = 0;

	token = strtok(line, " \t");
	while (token)
	{
		argv = realloc(argv, sizeof(char *) * (argc + 2));
		if (!argv)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t");
	}
	if (argv)
		argv[argc] = NULL;
	return (argv);
}
