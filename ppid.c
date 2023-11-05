#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		printf("child forked: %d\n", pid);
	}
	else
	{
		printf("parent porcess: %d\n", pid);
	}

	return (0);
}
