#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void) {
    char input[] = "this is the first command #this is the second command this is the third command\n";
    char *p1, *p2, *p3, modified_input[100];  // Adjust the size according to your needs
    int size = 0;

    p1 = input;
    p2 = modified_input;
    p3 = p2;

    while (*p1 != '\0') {
        if (*p1 == '&' && *(p1 + 1) == '&') {
	    printf("%s\n", p3);
            p1 += 2;  // Skip the '&&'
	    p3 = p2;
        } else if (*p1 == '|' && *(p1 + 1) == '|') {
	    printf("%s\n", p3);
            p1 += 2;  // Skip the '||'
	    p3 = p2;
        } else if (*p1 == ';') {
	    printf("%s\n", p3);
            p1++;
	    p3 = p2;
        } 
	else if (*p1 == '#') {
	    printf("%s\n", p3);
	    p3 = p2;
	    break;
		
	}else {
            *p2++ = *p1++;
	    size++;
        }
    }

    *p2 = '\0';  // Null-terminate the modified string

    printf("%s\n", p3);

    return 0;
}
