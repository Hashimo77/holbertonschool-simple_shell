#include "shell.h"

/**
 * simple_shell - Displays prompt, reads input and executes commands
 */
void simple_shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;
	char **argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (line[0] == '\0')
			continue;

		argv = parse_command(line);
		if (argv[0] == NULL)
		{
			free(argv);
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(argv);
			free(line);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execute_command(argv);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
		free(argv);
	}
	free(line);
}
