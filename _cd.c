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
}
char * _cd(char *newdir)
{
	char buff[1024];
	char *dir;
	char *parentdir;
	
	dir = getcwd(buff, 1024);
	printf("first directory : %s\n",dir);
	
	if (chdir(newdir) == -1)
	{
	printf("cd failed wrong directory\n");
	}
	else
	{
		if (strcmp(newdir, "..") == 0)
		{
			
			parentdir = get_home();
			chdir(parentdir);
			dir = getcwd(buff, 1024);
			printf("new dir :%s\n",dir);
		}
		if (strcmp(newdir, "-") == 0)
		{
		}
	}
	free(parentdir);
}

int main()
{
	char *current_dir = _cd("..");
	char *homepath= get_home();
	printf("home return %s\n",homepath);
	return 0;
}
