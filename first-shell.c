#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int ac, char **av)
{	int i = 0;
	char *buffer = malloc(sizeof(char));
	char *command= malloc(sizeof(char) * strlen(buffer));
       char *token;
       char *delim = " ";
	size_t n;
       int num,childvalue;
	pid_t child_pid;	
	char *charg[]= {"/bin/ls",NULL};

       printf("Xshell$ ");
	num = getline(&buffer, &n, stdin);
	strcpy(command,buffer);
	token = strtok(command, delim);

child_pid = fork();
if (child_pid == -1)
{
	printf("execution failed");
}
if (child_pid == 0)
{
    childvalue = execve(charg[0], charg, NULL);
}
else
{
	wait(NULL);
	execve(av[0], av, NULL);
	printf("PARENT ");
}
	
	free(buffer);
	free(command);
	return (0);
}
