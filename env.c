#include "headers.h"

/**
 *_setenv - changes or adds an environment variable
 *@name: env key
 *@value: env value
 *@overwrite: if non-zero it overwrites existing env values
 *
 *Return: 0 on success, -1 of failure
 **/
int _setenv(const char *name, const char *value, int overwrite)
{
	char *token, **ptr, *p;
	extern char **environ;
	int i, x, size = 0, found = 0, place = 0;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(strdup(environ[i]), "=");
		if (strcmp(token, name) == 0)
		{
			found = 1;
			place = i;
			break;
		}
	}
	while (environ[size])
		size++;
	ptr = malloc((size + 2) * sizeof(char *));
	if (!ptr)
		return (-1);
	for (x = 0; x < size; x++)
	{
		ptr[x] = strdup(environ[x]);
	}
	if (found && overwrite)
	{
		p = cat(name, value);
		free(environ[place]);
		ptr[place] = strdup(p);
		environ = ptr;
	}
	else if (!found)
	{
		p = cat(name, value);
		ptr[size] = strdup(p);
		ptr[size + 1] = NULL;
		environ = ptr;
	}
	return (0);
}
/**
 *_getenv-getting enviroment varaiable
 *Return:0success
 **/
int _getenv(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (0);
}
/**
 *_unsetenv-removing certain enviroment variables
 *@name:variable to change
 *Return:new enviroment 
 **/
int _unsetenv(const char *name)
{
	char *token, **ptr;
	extern char **environ;
	int i, x, size = 0, found = 0, place = 0;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(strdup(environ[i]), "=");
		if (strcmp(token, name) == 0)
		{
			found = 1;
			place = i;
			break;
		}
	}
	if (!found)
		return (0);
	while (environ[size])
		size++;

	ptr = malloc(size * sizeof(char *));
	if (!ptr)
		return (-1);
	for (x = 0; x < place; x++)
	{
		printf("%s\n", environ[x]);
		ptr[x] = strdup(environ[x]);
	}
	for (x = place + 1; x < size; x++)
	{
		printf("%s\n", environ[x]);
		ptr[x - 1] = strdup(environ[x]);
	}
	environ = ptr;
	return (0);
}
/**
 *cat-concatanate two string
 *@s1:first string
 *@s2:second string
 *Return:concatanated string
 **/
char *cat(const char *s1, const char *s2)
{
	char *p, *ptr;

	ptr = malloc(strlen(s1) + strlen(s2) + 2);
	if (!ptr)
		return (NULL);

	p = ptr;
	while (*s1)
		*ptr++ = *s1++;

	*ptr++ = '=';

	while (*s2)
		*ptr++ = *s2++;

	*ptr = '\0';

	return (p);
}
