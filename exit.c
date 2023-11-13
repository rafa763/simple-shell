#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
 * _exitshell:exit the shell
 * status:user input to exit command
 */
int _exitshell(int status)
{
  if (status == 0 || !status)
  exit(0);

  else if (status > 0)
  exit(status);

  if (status < 0)
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
    int signal = 1;
    int i;
    unsigned int num = 0,flag = 0,result = 0;

    for (i = 0;  str[i] != '\0' && flag != 2; i++)
    {
        if (str[i] == '-')
            signal *= -1;

        if (str[i] >= '0' && str[i] <= '9')
        {
            flag = 1;
            num *= 10;
            num += (str[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (signal == -1)
        result = -num;
    else
        result = num;

    return (result);
}
int main(void)
{ 
  int num = string2num("-332");
  printf("%d\n",num);
}
