#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - a program that executes the command ls -l /tmp in 5 different child processes
 */
int main(void)
{
	int i, stat;
	pid_t pid;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			printf("Child cannot be created\n");
			exit (1);
		}
		else if (pid == 0)
		{
			execve("/bin/ls", args, NULL);
			perror("Error in child");
		}
		else
		{
			wait(&stat);	
		}
	}

	return (0);
}
