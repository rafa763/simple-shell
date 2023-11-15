#include <headers.h>
char *getpath(char *command)
{
    int i, stat;
    char *token, *path = "", full[1024];
    extern char **environ;
    char *sign = "/";
    char *finaloutput;

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
//	printf("full: %s\n",full);
	path= strdup(full);
//	printf("path: %s\n",path);
        stat = access(path, X_OK);
        if (stat == 0)
	{
		finaloutput = path;
            free(path);
	    return (finaloutput);
	}
        token = strtok(NULL, ":");
	free(path);
    }
    return (NULL);
}
