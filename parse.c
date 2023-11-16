#include "headers.h"

/**
 * processToken - Process a token and update the pointers accordingly.
 *
 * @p1: Input string pointer.
 * @p2: Buffer pointer.
 * @p3: Current position pointer.
 * @buffer: Buffer for storing tokens.
 *
 * Return: Updated pointer after processing the token.
 */
char *processToken(char *p1, char **p2, char **p3, char *buffer)
{
	int res;

	if (*p1 == '&' && *(p1 + 1) == '&')
	{
		*p2 = processAnd(p2, p3, buffer);
		p1 += 2;  /* Skip the '&&' */
	}
	else if (*p1 == '|' && *(p1 + 1) == '|')
	{
		*p2 = '\0';
		res = process(*p3);
		if (res == 0)
			return (0);
		p1 += 2;  /* Skip the '||' */
		*p2 = buffer;
		*p3 = *p2;
	}
	else if (*p1 == ';')
	{
		processCommand(p3, p2);
		p1++;
		*p2 = buffer;
		*p3 = *p2;
	}
	else if (*p1 == '#' && *(p1 - 1) == ' ')
	{
		processCommand(p3, p2);
		*p3 = *p2;
		p1++;  /* Skip the '#' */
	}
	else
	{
		**p2 = *p1;
		(*p2)++;
		p1++;
	}

	return (p1);
}

/**
 * processAnd - process '&&' token and update the pointers accordingly.
 *
 * @p2: Buffer pointer.
 * @p3: Current position pointer.
 * @buffer: Buffer for storing tokens.
 *
 * Return: Updated buffer pointer.
 */
char *processAnd(char **p2, char **p3, char *buffer)
{
	**p2 = '\0';
	processCommand(p3, p2);
	return (buffer);
}

/**
 * processCommand - process a single command token.
 *
 * @p3: Current position pointer.
 * @p2: Buffer pointer.
 *
 * Return: void
 */
void processCommand(char **p3, char **p2)
{
	**p3 = '\0';
	process(*p3);
	*p3 = *p2;
}

/**
 * parse - parse the input string and execute commands accordingly.
 *
 * @input: User input to the command line.
 *
 * Return: 0 on success.
 */
int parse(char *input)
{
	char *p1, *p2, *p3;
	char *buffer = malloc(1024);

	if (buffer == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	p1 = input;
	p2 = buffer;
	p3 = p2;

	while (*p1 != '\0')
		p1 = processToken(p1, &p2, &p3, buffer);

	*p2 = '\0';  /* Null-terminate the modified string */
	process(p3);

	free(buffer);

	return (0);
}
