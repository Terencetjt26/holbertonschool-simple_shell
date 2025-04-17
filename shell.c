#include "shell.h"

/**
 * main - open a shell
 * Return: status
 */
int main(void)
{
	char *buffer = NULL;
	size_t read_size = 0;
	ssize_t buffer_size = 0;
	int status = 0;

	while (1)
	{
		if (isatty(0))
			printf("cisfun$ ");

		buffer_size = getline(&buffer, &read_size, stdin);

		if (buffer_size == -1 || _strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			break;
		}
	}

	return (status);
}
