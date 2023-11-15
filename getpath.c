#include "headers.h"
char *getpath(char *command)
{
    int i, stat;
    char *token, *path = "", full[1024];
    extern char **environ;
    char *sign = "/";

    stat = access(command, X_OK);
    if (stat == 0)
        return (command);

    for (i = 0; environ[i]; i++)
    {
        token = strtok((environ[i]), "=");

        if (strcmp("PATH", token) == 0)
        {
            token = strtok(NULL, "=");
            break;
        }
    }


    token = strtok(token, ":");
    while (token)
    {
        strcpy(full,token);
        strcat(full,sign);
        strcat(full,command);
	path= strdup(full);
        stat = access(path, X_OK);
        if (stat == 0)
	{
            return(path);
	}
        token = strtok(NULL, ":");
	free(path);
    }
    return (NULL);
}
