#include "shell.h"

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
				printf("cisfun:%s$ ", cwd);
		}
	}
}
