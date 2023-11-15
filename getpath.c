#include "headers.h"

char *getpath(char *command)
{
	int i, stat;
	char *token, *path = NULL, *full, *p, *p2, *p3;
	extern char **environ;

	stat = access(command, X_OK);
	if (stat == 0)
		return (command);

	for (i = 0; environ[i]; i++)
	{
		p = strdup(environ[i]);
		token = strtok(p, "=");

		if (strcmp("PATH", token) == 0)
		{
			token = strtok(NULL, "=");
			path = token;
			break;
		}
		free(p);
	}

	if (!path)
	{
		free(p);
		return (NULL);
	}

	token = strtok(token, ":");
	while (token)
	{
		p2 = strdup(token);
		p3 = strdup(command);
		full = (char *)malloc(strlen(p2) + strlen("/") + strlen(p3) + 1);
		if (full == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		strcpy(full, p2);
		strcat(full, "/");
		strcat(full, p3);

		free(p2);
		free(p3);
		stat = access(full, X_OK);
		if (stat == 0)
			break;
		else
		{
			free(full);
			full = NULL;
		}

		token = strtok(NULL, ":");
	}

	free(p);
	return (full);
}
