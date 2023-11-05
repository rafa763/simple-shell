#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        // Error or end of file
        free(line);
        return NULL;
    }

    // Remove the trailing newline character, if it exists
    if (line[nread - 1] == '\n') {
        line[nread - 1] = '\0';
    }

    return line;
}

int main() {
    char *input;
    while (1) {
        printf("$ ");
        input = readline();
        if (input == NULL) {
            break; // Exit on error or end of file
        }
        printf("%s\n", input);
        free(input);
    }

    return 0;
}

