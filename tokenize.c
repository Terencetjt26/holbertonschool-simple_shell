#include "shell.h"

/**
 * tokenize - splits a string into tokens
 * @buffer: string to split
 * Return: array of tokens
 */
char **tokenize(char *buffer)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0, size = 10;

	if (buffer == NULL || _empty(buffer))
		return (NULL);

	tokens = malloc(sizeof(char *) * size);
	if (tokens == NULL)
		return (NULL);

	token = strtok(buffer, " \n");
	while (token != NULL)
	{
		if (i >= size)
		{
			size *= 2;
			tokens = realloc(tokens, sizeof(char *) * size);
			if (tokens == NULL)
				return (NULL);
		}

		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			while (--i >= 0)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;

	return (tokens);
}
