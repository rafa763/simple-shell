#include <stdio.h>

int _exitshell(void)
{
  printf("\nexit\n");
  _exit(0);
}
