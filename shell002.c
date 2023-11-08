#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - first version of a super simple shell that can run commands with their full path, without any argument.
 */
int main(int ac, char **av)
{
	char *lineptr = NULL;
	size_t size = 0;
	ssize_t stat = 0;
	int ex;
	pid_t pid;


	// always prompt the user
	while (1)
	{
		// PS1
		printf("#cisfun$ ");
		// read from the standard input
		stat = getline(&lineptr, &size, stdin);
		if (stat == -1)
		{
			free(lineptr);
			break;
		}

		if (lineptr[size - 1] == '\n')
		{
			lineptr[size - 1] = '\0';
			break;
		}

		char *input_copy = strdup(lineptr);
		char *command = strtok(input_copy, " ");
		char *arg = strtok(NULL, " ");
		char *args[3];
		args[0] = command;
		if (arg != NULL) {
			args[1] = arg;
			args[2] = NULL; // Ensure a NULL terminator for execve
		} else {
			args[1] = NULL; // No arguments
			args[2] = NULL;
		}
		
		//command read is working fine at this point
		pid = fork();
		if (pid < 0)
		{
			perror("Error in forking:");
			exit(1);
		}
		else if (pid == 0)
		{
			// this is the child process to execute commands
		
			ex = execve(args[0], args, NULL);
			if (ex == -1)
				perror("Error in child process:");
		}
		else
		{
			// this is the parent process
			int status;
			wait(&status);
		}
	}

	return (0);
}
