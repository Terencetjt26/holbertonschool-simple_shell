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
 * display_prompt - displays the shell prompt
 * Return: void
 */
void display_prompt(void)
{
	char cwd[PATH_MAX];
	char *user = _getenv("USER");

	if (isatty(0))
	{
		if (getcwd(cwd, sizeof(cwd)))
		{
			if (user)
				printf("%s@cisfun:%s$ ", user, cwd);
			else
				printf("cisfun: %s$ ", cwd);
		}
	}
}

/**
 * process_input - Processes user input and executes commands
 * @data: Pointer to the shell data structure
 * Return: 0 on success, -1 on failure
 */
int process_input(sh_t *data)
{
	size_t read_size = 0;
	ssize_t buffer_size = 0;

	buffer_size = getline(&data->buffer, &read_size, stdin);
	if (buffer_size == -1)
	{
		free(data->buffer);
		return (-1);
	}
	data->buffer[buffer_size - 1] = '\0';

	if (_empty(data->buffer) == 1)
	{
		data->status = 0;
		return (0);
	}

	data->args = tokenize(data->buffer);

	if (handle_builtin(data) == 0)
	{
		free(data->args);
		return (0);
	}

	data->args[0] = get_path(data->args[0]);
	if (data->args[0] != NULL)
		data->status = execute_command(data->args);
	else
		perror("Command not found");

	free(data->args);
	return (0);
}
