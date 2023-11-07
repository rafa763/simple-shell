#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct dirlist
{
	char *dirname;
	unsigned int len;
	struct dirlist *next;
} dirlist;


int main(void)
{
	int i;
	char *token, *path;
	dirlist *head, *temp;
	extern char **environ;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");

		if (strcmp("PATH", token) == 0)
		{
			token = strtok(NULL, "="); 
			path = token;
			break;
		}
	}

	if (!path)
		return (0);
	
	token = strtok(token, ":");
	head = NULL;
	while (token)
	{
		i = 0;
		while (token[i])
			i++;

		temp = malloc(sizeof(dirlist));

		if (!temp)
			return (1);

		temp->dirname = strdup(token);
		if (!temp->dirname)
		{
			free(temp);
			return (1);
		}

		temp->len = i;
		temp->next = head;
		head = temp;
		printf("[from print loop] %s\n", token);
		token = strtok(NULL, ":");
	}

	/* print the list to test it */
	/*
	while (head != NULL)
	{
		if (head->dirname == NULL)
			printf("[0] (nil)\n");
		else
			printf("[print from lnkdlst] (%u) %s\n", head->len, head->dirname);
		head = head->next;
	}
	*/

	free(temp);
	return (0);
}	
