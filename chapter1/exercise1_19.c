// exercise 1-19: write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time 
#include <stdio.h>

#define MAXLINE 1000

void reverse(char str[]);
int mygetline(char line[], int limit);

main() {
    char line[MAXLINE];
    while (mygetline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
}

void reverse(char str[]) {
    int i, c, length;
    i = 0;
    length = 0;
    while ((c = str[i]) != '\0' && c != '\n') {
        ++i;
    }
    length = i - 1;
    i = 0;
    while (i < length / 2) {
        int temp = str[i];
        str[i] = str[length - i];
        str[length - i] = temp;
        ++i;
    }
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