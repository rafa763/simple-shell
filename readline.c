#include "headers.h"
#include <stdio.h>
#include <stdlib.h>

char *readline()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1) {
		/* Error or end of file */
		free(line);
		return NULL;
	}

	/* Remove the trailing newline character, if it exists */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return line;
}
