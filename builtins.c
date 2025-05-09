#include "shell.h"

/**
 * builtin_exit - exits the shell
 * @data: data structure containing shell information
 * Return: 0 on success, -1 on failure
 */
int builtin_exit(sh_t *data)
{
	int status = 0;

	if (data->args[1])
	{
		status = _atoi(data->args[1]);
		if (status == -1)
		{
			return (-1);
		}
	}
	free(data->buffer);
	free(data->args);
	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * builtin_cd - changes the current directory
 * @data: data structure containing shell information
 * Return: 0 on success, -1 on failure
 */
int builtin_cd(sh_t *data)
{
	char *dir = data->args[1];

	if (dir == NULL)
		dir = _getenv("HOME");
	if (dir == NULL || chdir(dir) == -1)
		return (-1);
	return (0);
}

/**
 * handle_builtin - handles built-in commands
 * @data: data structure containing shell information
 * Return: 0 on success, -1 on failure
 */
int handle_builtin(sh_t *data)
{
	int i = 0;
	builtin_t builtins[] = {
		{"exit", builtin_exit},
		{"env", _env},
		{"cd", builtin_cd},
		{NULL, NULL}
	};

	while (builtins[i].name)
	{
		if (_strcmp(data->args[0], builtins[i].name) == 0)
		{
			return (builtins[i].f(data));
		}
		i++;
	}
	return (-1);
}

/**
 * handle_builtin_commands - handles builtin commands
 * @data: Pointer to the shell data structure
 * Return: 0 on success, 1 on failure
 */
int handle_builtin_commands(sh_t *data)
{
	if (handle_builtin(data) == 0)
	{
		return (0);
	}
	return (1);
}
