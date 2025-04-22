#include "shell.h"

/**
 * execute_command - execute a command
 * @args: array of arguments
 * Return: status of the command
 */
int execute_command(char **args)
{
	int status = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (status);
}
