#include "shell.h"

/**
 * execute - executes a command
 * @args: array of arguments
 * Return: status of the command
 */
int execute(char **args)
{
	int status = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (status);
}

/**
 * main - open a shell
 * Return: status
 */
int main(void)
{
	char *buffer = NULL, **args = NULL;
	size_t read_size = 0;
	ssize_t buffer_size = 0;
	int status = 0;

	while (1)
	{
		if (isatty(0))
			printf("#cisfun$ ");

		buffer_size = getline(&buffer, &read_size, stdin);
		if (buffer_size == -1 || _strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			break;
		}
		buffer[buffer_size - 1] = '\0';

		if (_strcmp("env", buffer) == 0)
		{
			_env();
			continue;
		}

		if (_empty(buffer) == 1)
		{
			status = 0;
			continue;
		}

		args = tokenize(buffer);
		args[0] = get_path(args[0]);

		if (args[0] != NULL)
			status = execute(args);
		else
			perror("An error occurred");
		free(args);
	}

	return (status);
}
