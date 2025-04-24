#include "shell.h"

/**
 * read_user_input - reads user input from stdin
 * @data: Pointer to the shell data structure
 * Return: 0 on success, -1 on failure
 */
int read_user_input(sh_t *data)
{
	size_t read_size = 0;
	ssize_t buffer_size = getline(&data->buffer, &read_size, stdin);

	if (buffer_size == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);

		free(data->buffer);
		return (-1);
	}

	if (data->buffer[buffer_size - 1] == '\n')
		data->buffer[buffer_size - 1] = '\0';

	return (0);
}
