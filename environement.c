#include "shell.h"

/**
 * _getenv - get the value of an environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable
 */
char *_getenv(char *name)
{
	int i, j;
	size_t len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < (int)len; j++)
		{
			if (environ[i][j] != name[j])
				break;
		}
		if (j == (int)len && environ[i][j] == '=')
			return (_strdup(environ[i] + len + 1));
	}
	return (NULL);
}

/**
 * _env - print the environment variables
 * @data: data structure containing shell information
 * Return: 0 on success, -1 on failure
 */
int _env(sh_t *data)
{
	int i = 0;
	(void)data;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
