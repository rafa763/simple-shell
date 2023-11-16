#ifndef HEADERS_H
#define HEADERS_H


/* Importing Libraries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

extern char **environ;

/* Function Prototypes */
char *readline();
int process(char *input);
int checkcommand(char *command, char **args);
char *getpath(char *command);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *cat(const char *s1, const char *s2);
int _getenv(void);
int parse(char *input);
char *processToken(char *p1, char **p2, char **p3, char *buffer);
char *processAnd(char **p2, char **p3, char *buffer);
void processCommand(char **p3, char **p2);

#endif /* HEADERS_H */
