#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Error:");
		exit(1);
	}
	else if (pid == 0)
	{
		/* this is the child process */
		printf("child process and it's parent id is %d\n", getppid());
	}
	else
	{
		printf("parent process id is %d\n", getpid());
	}
	return (0);
}

