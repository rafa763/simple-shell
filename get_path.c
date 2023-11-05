#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int ac, char **av, char **env)
{
/*node for linked list of directorys*/
struct dir
{
char *name;
struct dir *next;
};	
	char *PATH;char *token;char buffer[1024] ;char *path;
	struct dir *head = malloc(sizeof(struct dir));
	struct dir *current = malloc(sizeof(struct dir));
	int i = 0;
	/*getting path BUT NEED TO BE REPLACED (NOT ALLOWED FUNCTION)*/
	PATH = getenv("PATH");
	/*printf("%s\n",PATH);*/
	/*breaking down the path to directorys*/
	token = strtok(PATH, ":");
	/*printf("%s\n",token);*/
	/*creating first node in linked list*/
	head->name = token;
	head->next = NULL;
	/*copying directory to add needed command*/
	strcpy(buffer,token);
	strcat(buffer,"/");
	/*hard code NEEDED TO BE REPLACED (USER INPUT)*/
	strcat(buffer,"ls");
/*	printf("buffer: %s\n",buffer);*/
	/*checking if command in directory (can be optimised)*/
	if(access(buffer,X_OK) == 0)
	{
	printf("found command : %s\n",buffer);
	printf("found\n");
	/*terminate with first directory with command*/
	return 0;
	}
/*continue parsing directorys*/
	while (token)
	{
/*	printf("head: %s\n",root->name);	*/	
	token = strtok(NULL, ":");
	/*create second node in linked list*/
	current->name = token;
	current->next = NULL;
	/*linking first and second node*/
	head->next = current;
/*	printf("current : %s\n",current->name);*/
/* same proccess with first node repeated 
 * maybe a loop can do it better?? (need to be optimized if possible)
 * */
	strcpy(buffer,token);
	strcat(buffer,"/");
	strcat(buffer,"ls");
/*      printf("buffer: %s\n",buffer);*/
	if(access(buffer,X_OK) == 0)
	{
	printf("found command : %s\n",buffer);
	printf("found\n");
	return (0);
	}
}
return 0;
}
