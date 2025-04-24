#include "shell.h"

#define BUFFER 1024

/**
 * tokenize - splits a string into tokens
 * @buffer: string to split
 * Return: array of tokens
 */
char **tokenize(char *buffer)
{
	char **tokens;
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
