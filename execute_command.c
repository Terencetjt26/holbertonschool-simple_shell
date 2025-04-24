#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: string to search
 * @c: character to find
 * Return: pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

/**
 * execute_command - execute a command
 * @args: array of arguments
 * Return: status of the command
 */
int execute_command(char **args)
{
	int status = 0;
	pid_t pid;

	if (access(args[0], X_OK) == -1)
	{
		perror("access");
		return (-1);
	}

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
		if (wait(&status) == -1)
		{
			perror("wait");
			return (-1);
		}

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
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
	char *full_path = NULL;
	char *cmd_args[3];



	if (_strchr(data->args[0], '/') != NULL)
	{
		data->status = execute_command(data->args);
	}
	else
	{
		full_path = get_path(data->args[0]);
		if (full_path)
		{
			cmd_args[0] = full_path;
			cmd_args[1] = data->args[1];
			cmd_args[2] = NULL;

			data->status = execute_command(cmd_args);
			free(full_path);
		}
		else
		{
			perror("get_path");
			return (-1);
		}
	}

	return (0);
}
