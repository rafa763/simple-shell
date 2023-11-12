#include "headers.h"

int checkcommand(char *command, char **args)
{
	int stat, i;
	char *result, *prompt;
	pid_t pid;

	result = getpath(command);
	prompt = "command not found\n";
	if (!result)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		return (-1);
	}

	pid = fork();
	if (pid < 0)
		perror("Error in forking");
	else if (pid == 0)
	{
		execve(result, args, NULL);
		perror("Error in child");
	}
	else
	{
		wait(&stat);
		return (0);
	}

	return (0);
}
