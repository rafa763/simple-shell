#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
//notes:
//want to get/return string of home direstory from this function
//handle cd - too 
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
			printf("return home :%s\n",home);
			return (home);
			break;
                }
        }

        if (!path)
                return (0);
        token = strtok(token, ":");
        while (token)
        {
               printf("inside home %s\n", token);
		token = strtok(NULL, ":");
        }
        return (home);
}
char * _cd(char *newdir)
{
	char buff[1024];
	char *dir;
	
	dir = getcwd(buff, 1024);
       // printf("%s\n",dir);
	
	if (chdir(newdir) == -1)
	{
	printf("cd failed wrong directory\n");
	}
	else
	{
		if (newdir == "/root")
		{
			newdir = get_home();
			if(chdir(newdir) == 0)
			printf("worked");
		}
	dir = getcwd(buff, 1024);
        printf("new dir :%s\n",dir);
	}
}

int main()
{
	char *current_dir = _cd("/root");
	char *homepath= get_home();
	printf("home return %s\n",homepath);
	return 0;
}
