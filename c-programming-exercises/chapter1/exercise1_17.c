// exercise 1-17: write a program to print all input lines that are longer than 80 characters
#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int limit);
void copy(char to[], char from[]);

// print all input lines longer than 80 characters
main() {
    char line[MAXLINE];
    int len;
    int minLength = 80;

    while((len = mygetline(line, MAXLINE)) > 0) {
        if (len >= minLength) {
            printf("%s", line);
        }
    }

    return 0;
}

int mygetline(char line[], int limit) {
    int i,c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i, c;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}