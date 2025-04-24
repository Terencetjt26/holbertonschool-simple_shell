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
	pid_t pid;
	char *path_cmd;

	if (_strchr(args[0], '/'))
		path_cmd = _strdup(args[0]);
	else
		path_cmd = get_path(args[0]);

	if (path_cmd == NULL)
	{
		printf("Command not found: %s\n", args[0]);
		return (-1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path_cmd, args, environ) == -1)
		{
			perror("execve");
			free(path_cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		wait(NULL);
	else
	{
		perror("fork");
		return (-1);
	}

	free(path_cmd);

	return (0);
}
