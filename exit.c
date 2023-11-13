#include <stdio.h>
#include <unistd.h>
#include "headers.h"
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
