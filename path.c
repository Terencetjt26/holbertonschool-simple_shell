#include "shell.h"

/**
 * get_path - gets the full path of a command
 * @command: command to find
 * Return: full path of the command
 */
char *get_path(char *command)
{
	char *path = _getenv("PATH");
	char *path_copy, *token;
	struct stat buffer;

	if (!path)
		return (NULL);

	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char *full_path = malloc(_strlen(token) + _strlen(command) + 2);

		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (stat(full_path, &buffer) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
