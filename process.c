#include "headers.h"

#define MAX_ARGS 20
/**
 *process-takes user input and tokenize it to reach final executable command
 *@input:user input to command line
 *Return:command stats value
 **/
int process(char *input)
{
	char *token, *command, *args[MAX_ARGS];
	int argcount = 0, stat;
	char buff[1024];

	strcpy(buff, input);
	token = strtok(buff, " ");
	command = token;
	args[argcount++] = token;
	while (token && argcount < MAX_ARGS)
	{

		token = strtok(NULL, " ");
		args[argcount++] = token;
	}
	args[argcount] = NULL;

	if (strcmp(command, "env") == 0)
		_getenv();
/*	if (strcmp(command, "setenv") == 0)
		_setenv(*args);*/
	if (strcmp(command, "unsetenv") == 0)
		_unsetenv(*args);
	
	else
	{
		stat = checkcommand(command, args);
	}
		return (stat);
}
