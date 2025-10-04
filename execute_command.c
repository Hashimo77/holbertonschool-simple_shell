#include "shell.h"

/**
 * execute_command - Forks and executes a command using execve
 * @cmd: The command to execute (absolute path required)
 */
void execute_command(char *cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		char *argv[2];

		argv[0] = cmd;
		argv[1] = NULL;

		if (execve(cmd, argv, environ) == -1)
			perror("./shell");

		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
