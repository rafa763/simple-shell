#include "headers.h"

char *getpath(char *command)
{
	int i, stat;
	char *token, *path, *full;
	extern char **environ;

	stat = access(command, X_OK);
	if (stat == 0)
		return (command);

	for (i = 0; environ[i]; i++)
	{
		token = strtok(strdup(environ[i]), "=");

		if (strcmp("PATH", token) == 0)
		{
			token = strtok(NULL, "=");
			path = token;
			break;
		}
	}

	if (!path)
		return (NULL);

	token = strtok(token, ":");
	while (token)
	{
		/*printf("%s/%s\n", token, command);*/
		full = strcat(strdup(token), strcat(strdup("/"), strdup(command)));
		/* printf("%s\n", full);*/
		stat = access(full, X_OK);
		if (stat == 0)
			return (full);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
