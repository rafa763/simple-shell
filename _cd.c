#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//notes:
//want to get/return string of home direstory from this function
//handle cd - too (return to previous directory)
//
char *get_home(void)
{
        int i;
        char *token, *path,* home;
        extern char **environ;

        for (i = 0; environ[i]; i++)
        {
                token = strtok(environ[i], "=");

                if (strcmp("HOME", token) == 0)
                {
                        token = strtok(NULL, "=");
                        path = token;
			home = strdup(token);
			if (home != NULL)
			return (home);
                }
        }
	free(home);
}
char *get_previous(void)
{
        int i;
        char *token,* previous;
        extern char **environ;

        for (i = 0; environ[i]; i++)
        {
                token = strtok(environ[i], "=");

                if (strcmp("OLDPWD", token) == 0)
                {
                        token = strtok(NULL, "=");
			previous = strdup(token);
			if (previous != NULL)
			return (previous);
                }
        }free(previous);
}
void * _cd(char *newdir)
{
	char buff[1024];
	char *dir;
	char *parentdir;
	
	dir = getcwd(buff, 1024);
	printf("first directory : %s\n",dir);
	
		if (newdir == NULL)
		{
			
			parentdir = get_home();
			chdir(parentdir);
			dir = getcwd(buff, 1024);
			printf("new dir :%s\n",dir);
		}
		else if (strcmp(newdir, "-") == 0)
		{
			parentdir = get_previous();
			chdir(parentdir);
			dir = getcwd(buff, 1024);
			printf("new dir :%s\n",dir);
		}
		else
		{
			if (chdir(newdir) == -1)
			{
			printf("cd failed wrong directory\n");
			}
			chdir(newdir);
			dir = getcwd(buff, 1024);
			printf("new dir: %s\n",dir);
		}	
	free(parentdir);
}

int main()
{
	_cd(NULL);
	_cd("-");
	_cd("/bin");
	//_cd("/root");
	return 0;
}
