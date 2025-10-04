#include "shell.h"

/**
 * main - Entry point for simple shell
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	(void)ac;
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read = getline(&line, &len, stdin);
		if (read == -1)
			break;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (_strcmp(line, "exit") == 0)
			break;

		execute_command(line);
	}
	free(line);
	return (0);
}
