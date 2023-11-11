#include <stdio.h>
/*
 * _exitshell:exit the shell
 * status:user input to exit command
 */
int _exitshell(status)
{
  if (status == 0)
  {printf("\nnormal exit\n");
  _exit(0);}

  else if (status > 0)
  {printf("\n exit\n");
  _exit(status);}
  
  if (status < 0)
 { printf("\nerror exit\n");
  _exit(status);
}

int main(void)
{
_exitshell();
}
