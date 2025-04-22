#include "shell.h"

/**
 * _getenv - get the value of an environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable
 */
char *_getenv(char *name)
{
	int i = 0, j;
	int status = 0;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != name[j])
			{
				status = 0;
				break;
			}
		}
		if (status == 1 && environ[i][j] == '=')
		{
			break;
		}
		i++;
	}

	return (environ[i] + j + 1);
}

/**
 * _env - print the environment variables
 * Return: void
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
