#include "headers.h"

int checkcommand(char *command, char **args)
{
	int stat;
	char *result, *prompt;
	pid_t pid;
	extern char **environ;

	result = getpath(command);
	prompt = "command not found\n";
	if (!result)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		free(result);
		return (-1);
	}

	pid = fork();
	if (pid < 0)
		perror("Error in forking");
	else if (pid == 0)
	{
		execve(result, args, environ);
		perror("Error in child");
	}
	else
	{
		wait(&stat);
		free(result);
		return (stat);
	}

	return (stat);
}
