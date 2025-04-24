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
	int i = 0;

	if (buffer == NULL || _empty(buffer))
		return (NULL);

	tokens = malloc(sizeof(char *) * (_strlen(buffer) + 1));
	if (tokens == NULL)
		return (NULL);

	token = strtok(buffer, " \n");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;

	return (tokens);
}
