#include "shell.h"

/**
 * read_line - Read a line from standard input
 *
 * Return: Pointer to the read line, or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	/* Remove newline character */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}
