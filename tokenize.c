#include "shell.h"

/**
 * tokenize - splits a string into tokens
 * @buffer: string to split
 * Return: array of tokens
 */
char **tokenize(char *buffer)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);

	token = strtok(buffer, " \t\r\n");
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;

	return (tokens);
}
