#include "headers.h"

/**
 * main - Entry point for the shell, handles the interactive and non-interactive
 * modes of the shell
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return - 0 on success, -1 of failure
 */
int main(void)
{
	char *input;
	char *prompt = "$ ";

	/* get the input from the user */
	if (isatty(STDIN_FILENO))
	{
		/* interactive */
		while (1)
		{
			write(STDOUT_FILENO, prompt, strlen(prompt));
			input = readline();
			if (input == NULL)
			{
				free(input);
				return (0);
			}
			if (strcmp(input ,"") != 0)
				parse(input);
			else
				free(input);
			/* exit_status = WEXITSTATUS(status);
			printf("Last exit status: %d\n", exit_status); */
		}
	}
	else
	{
		/* non interactive */
		input = readline();
		if (input == NULL)
		    return (0);
		parse(input);
		free(input);
	}

	return (0);
}
