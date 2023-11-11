#include <stdio.h>
#include <string.h>
/**
 *any string starting with # ignored
 *otherwise if # inside sentence gets printed 
 */
int _comment(char *string)
{
	int i = 0;
	//char *string = "# This is a comment";
	int len = strlen(string);
	char x;

	while (i < len)
	{
		x = string[i];
		
		if(x == '#' && string[i-1])	
		printf("%c",x);
	
		else if(x == '#')
			break;
		else
		printf("%c",x);
		i++;
	}
	printf("\n");
}
