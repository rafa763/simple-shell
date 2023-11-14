#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
 * _exitshell:exit the shell
 * status:user input to exit command
 */
int _exitshell(int status)
{
  if (status == 0)
  exit(EXIT_SUCCESS);

  else if (status > 0 || status < 0)
  exit(status);
}

/* exit with success*/
  void _successexit(void) {
    exit(EXIT_SUCCESS);}
 /* exit with failure*/
 void _failexit(void) {
    exit(EXIT_FAILURE);}
 /* exit with user input*/
  _exitshell(userinput);
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
int string2num(char *str)
{
	unsigned int num = 0,flag = 0,result = 0;
	int i, signal = 1;
    for (i = 0;  str[i] != '\0' && flag < 2; i++)
    {
        if (str[i] == '-')
            signal *= -1;

	else if (str[i] >= '0' && str[i] <= '9')
        {
            num *= 10;
            num += (str[i] - 48);
	    flag = 1;
	}
        else if (flag == 1)
            flag = 2;
    }

    if (signal == -1)
        result = -1 * num;
    else if (signal == 1)
        result = num;

    return (result);
}
int main(void)
{ 
  int num = string2num("-332");
  printf("%d\n",num);
}
