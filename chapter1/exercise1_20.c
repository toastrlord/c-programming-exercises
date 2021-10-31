// exercise 1-20: write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tabstop. Assume a fixed set of tab stops.
#include <stdio.h>

#define TAB_WIDTH 8
#define MAX_BUFFER 1000

int mygetline(char line[], int limit);
void detab(char to[], char from[]);
void printstr(char str[]);
void printstrAsInt(char str[]);

main() {
    char line[MAX_BUFFER];
    char detabbed[MAX_BUFFER];
    while (mygetline(line, MAX_BUFFER) > 0) {
        detab(detabbed, line);
        printf("%s", detabbed);
    }
}

int mygetline(char line[], int limit) {
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < limit - 1; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';

    return i;
}

void detab(char to[], char from[]) {
    int i, j, c;
    i = 0;
    j = 0;
    while ((c = from[i]) != '\0') {
        if (c == '\t') {
            int numSpaces = TAB_WIDTH - (j % TAB_WIDTH);
            for (int k = 0; k <= numSpaces; ++k) {
                to[j + k] = ' ';
            }
            j += numSpaces;
        }
        else {
            to[j] = from[i];
            ++j;
        }
        ++i;
    }
    to[j] = '\0';
}

void printstr(char str[]) {
    int i, c;
    i = 0;
    while ((c = str[i]) != '\0') {
        if (c == '\t') {
            putchar('t');
        }
        else if (c == ' ') {
            putchar('s');
        }
        else {
            putchar(c);
        }
        ++i;
    }
}

void printstrAsInt(char str[]) {
    int i, c;
    i = 0;
    while ((c = str[i]) != '\0') {
        printf("%3d ", c);
        ++i;
    }
    printf("\n");
}