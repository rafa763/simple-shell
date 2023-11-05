#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid = getppid();

	printf("parent process id is %d\n", pid);
	return (0);
}

