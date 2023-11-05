#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "a-e-i-o-u";

	char *token = strtok(str, "-");

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, "-");
	}

	return (0);
}
