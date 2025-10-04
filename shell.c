#include "shell.h"

/**
 * execute_command - Executes a given command
 * @command: command string (e.g. "/bin/ls" or "ls")
 */
void execute_command(char *command)
{
	pid_t pid;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
			perror("hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
