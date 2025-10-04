#include "shell.h"

/**
 * simple_shell - Displays a prompt and executes user commands
 */
void simple_shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;

	while (1)
	{
		/* Show prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			/* Handle Ctrl+D (EOF) */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			break;
		}

		/* Remove newline at end of input */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Ignore empty lines */
		if (line[0] == '\0')
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			/* Child process executes command */
			execute_command(line);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
}
