#include "headers.h"

#define MAX_ARGS 20
/**
 * takes the line that the user has provided and processes it
 */
int process(char *input)
{
	char *token, *command, *args[MAX_ARGS];
	int i, start = 0, argcount = 0;

	token = strtok(strdup(input), " ");
	command = token;
	args[argcount++] = token;
	//printf("command: %s\n", command);

	while (token && argcount < MAX_ARGS)
	{

		token = strtok(NULL, " ");
		args[argcount++] = token;
	}
	args[argcount] = NULL;

	if (strcmp(command, "env") == 0)
		_getenv();
	else
		checkcommand(command, args);

	return (0);
}
