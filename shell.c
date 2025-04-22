#include "shell.h"

/**
 * main - entry point of the shell
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	sh_t data = {NULL, 0, NULL};
	size_t read_size = 0;
	ssize_t buffer_size = 0;

	while (1)
	{
		if (isatty(0))
			printf("#cisfun$ ");

		buffer_size = getline(&data.buffer, &read_size, stdin);
		if (buffer_size == -1)
		{
			free(data.buffer);
			break;
		}
		data.buffer[buffer_size - 1] = '\0';

		if (_empty(data.buffer) == 1)
		{
			data.status = 0;
			continue;
		}

		data.args = tokenize(data.buffer);

		if (handle_builtin(&data) == 0)
		{
			free(data.args);
			continue;
		}

		data.args[0] = get_path(data.args[0]);
		if (data.args[0] != NULL)
			data.status = execute_command(data.args);
		else
			perror("Command not found");
		free(data.args);
	}
	return (data.status);
}
