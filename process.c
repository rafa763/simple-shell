#include "headers.h"

#define MAX_ARGS 20
/*
 *process-takes user input and tokenize it to reach final executable command
 *@input:user input to command line
 *Return:command stats value
 */
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

	/*if (strcmp(command, "env") == 0)
		_getenv();*/
	/**
	if (strcmp(command, "setenv") == 0)
		_setenv(*args);
	if (strcmp(command, "unsetenv") == 0)
		_unsetenv(*args);
		*/
	/*else
	{*/
		stat = checkcommand(command, args);
	
	free(command);
	return (stat);
}
/**
 *parse-parsing through each character in the command line arguments
 *@input:user input to commandline
 *Return:0success
 */
int parse(char *input)
{
	int res;
	char *p1, *p2, *p3, buffer[1024];  
	
	p1 = input;
	p2 = buffer;
	p3 = p2;
	while (*p1 != '\0')
	{
		if (*p1 == '&' && *(p1 + 1) == '&')
		{
			*p2 = '\0';
			res = process(p3);
			if (res != 0)
				return (0);
			p1 += 2;  /* Skip the '&&' */
			p2 = buffer;
			p3 = p2;
		}
		else if (*p1 == '|' && *(p1 + 1) == '|')
		{
			*p2 = '\0';
			res = process(p3);
			if (res == 0)
				return (0);
			p1 += 2;  /* Skip the '||' */
			p2 = buffer;
			p3 = p2;
		}
		else if (*p1 == ';')
		{
			*p2 = '\0';
			process(p3);
			p1++;
			p2 = buffer;
			p3 = p2;
		}
		else if (*p1 == '#' && *(p1 - 1) == ' ')
		{
			*p2 = '\0';
			process(p3);
			p3 = p2;
			return (0);
		}
		else
		{
			*p2++ = *p1++;
		}
	}

	*p2 = '\0';  /* Null-terminate the modified string */

	process(p3);

	return (0);
}
