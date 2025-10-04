#include "shell.h"

/**
 * execute_command - Executes a command using execve
 * @command: Command to execute (full path)
 */
void execute_command(char *command)
{
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	if (execve(command, argv, environ) == -1)
	{
		perror("./shell");
	}
}
