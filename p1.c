#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int i;
	char *token, *path;
	extern char **environ;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");

		if (strcmp("PATH", token) == 0)
		{
			token = strtok(NULL, "="); 
			path = token;
			break;
		}
	}

	if (!path)
		return (0);
	
	token = strtok(token, ":");
	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	return (0);
}	
