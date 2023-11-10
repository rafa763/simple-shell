#ifndef HEADERS_H
#define HEADERS_H


/* Importing Libraries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>


/* Function Prototypes */
char *readline();
int process(char *input);
int checkcommand(char *command, char **args);
char *getpath(char *command);

#endif /* HEADERS_H */
