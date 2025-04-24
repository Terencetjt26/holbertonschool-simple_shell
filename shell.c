#include "shell.h"

/**
 * main - entry point of the shell
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	sh_t data = {NULL, 0, NULL};
	int status = 0;

	while (1)
	{
		if (isatty(0))
			display_prompt();

		status = process_input(&data);
		if (status == -1)
			break;
	}
	return (data.status);
}

/**
 * process_input - Processes user input and executes commands
 * @data: Pointer to the shell data structure
 * Return: 0 on success, -1 on failure
 */
int process_input(sh_t *data)
{
	if (read_user_input(data) == -1)
		return (-1);

	if (_empty(data->buffer))
	{
		free(data->buffer);
		data->buffer = NULL;
		data->status = 0;
		return (0);
	}

	data->args = tokenize(data->buffer);

	if (!handle_builtin_commands(data))
	{
		data->status = 0;
		free(data->args);
		free(data->buffer);
		data->args = NULL;
		data->buffer = NULL;
		return (0);
	}

	if (execute_external_command(data) == -1)
	{
		data->status = 1;
	}

	free(data->args);
	free(data->buffer);
	data->buffer = NULL;
	data->args = NULL;

	return (data->status);
}
