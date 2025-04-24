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
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (status);
}

/**
 * execute_external_command - executes an external command
 * @data: Pointer to the shell data structure
 * Return: 0 on success, -1 on failure
 */
int execute_external_command(sh_t *data)
{
	if (data->args[0][0] == '.')
	{
		data->status = execute_command(data->args);
	}
	else
	{
		data->args[0] = get_path(data->args[0]);
		if (data->args[0])
		{
			data->status = execute_command(data->args);
		}
		else
		{
			perror("get_path");
			return (-1);
		}
	}
	return (0);
}
