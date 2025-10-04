#include "shell.h"

/**
 * execute_command - Executes a command using execve
 * @argv: Array of command and arguments
 */
void execute_command(char **argv)
{
	if (execve(argv[0], argv, environ) == -1)
		perror("./shell");
}
