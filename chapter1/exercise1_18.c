#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int limit);
void putstr(char line[]);

// remove trailing spaces and tabs from input
main() {
    char line[MAXLINE];
    while (mygetline(line, MAXLINE) > 0) {
        putstr(line);
    }

    return 0;
}

int mygetline(char line[], int limit) {
    int i, c;
    int endChars = 1;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    
    if (c == '\n') {
        line[i] = c;
        ++i;
        endChars = 2;
    }
    line[i] = '\0';
    i -= endChars;
    while ((c = line[i]) == ' ' || c == '\t' && i > 0) {
        for (int j = 0; j < endChars; ++j) {
            line[i + j] = line[i + j + 1];
        }
        --i;
    }
    if (line[0] == '\n') {
        line[0] = '\0';
        return 1;
    }
    else {
        return i + endChars;
    }
}

void putstr(char line[]) {
    int i, c;
    i = 0;
    while ((c = line[i]) != '\0') {
        putchar(c);
        ++i;
    }
}