#include <headers.h>
int process(char *input)
{
	char *token, *command, *args[MAX_ARGS];
	int i, start = 0, argcount = 0;
	char buf[1024];

	strcpy(buf,input);
	token = strtok(buf, " ");
	command = token;
	args[argcount++] = token;

	while (token && argcount < MAX_ARGS)
	{

		token = strtok(NULL, " ");
		args[argcount++] = token;
	}
	args[argcount] = NULL;

	checkcommand(command, args);
	return (0);
}
