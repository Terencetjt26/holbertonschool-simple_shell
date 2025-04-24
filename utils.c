#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, non-zero if not
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _empty - checks if a string is empty
 * @buffer: string to check
 * Return: 1 if empty, 0 if not
 */
int _empty(char *buffer)
{
	int i = 0;

	while (buffer[i])
	{
		if (buffer[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: integer value of the string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0;

	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = strlen(str);
	char *dup = malloc(len + 1);

	if (dup == NULL)
		return (NULL);

	strcpy(dup, str);
	return (dup);
}
