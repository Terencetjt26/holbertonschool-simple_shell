#include "shell.h"

/**
 * get_path - gets the full path of a command
 * @command: command to find
 * Return: full path of the command
 */
char *get_path(char *command)
{
	char *path = _getenv("PATH");
	char *path_copy, *dir, *full_path;
	size_t len;

	if (!path || !command)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		len = _strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
