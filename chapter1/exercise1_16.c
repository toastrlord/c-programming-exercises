// exercise 1-16: Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text
#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int limit);
void copy(char to[], char from[]);

// adjust the longest input line code so it can determine the length of an arbitrary sized string
main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    while((len = mygetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
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

    // my adjustments here
    if (c != '\n' && c != EOF) {
        while ((c = getchar()) != EOF && c != '\n') {
            ++i;
        }
    }

    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}