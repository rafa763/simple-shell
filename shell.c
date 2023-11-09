#include "headers.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	char *input;

	if (isatty(STDIN_FILENO))
	{
		// interactive
		while (1)
		{
			printf("$ ");
			input = readline();
			if (input == NULL)
				return (0);
			printf("%s\n", input);
			free(input);
		}
	}
	else
	{
		// non interactive
		input = readline();
		if (input == NULL)
		    return (0);
		printf("%s\n", input);
		free(input);
	}

	return (0);
}
