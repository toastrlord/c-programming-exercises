#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10
#define MAX_LINE_LENGTH 1000
#define MAX_LINES 1000

void tail(int, char **, int);
int mygetline(char *, int);

main(int argc, char *argv[]) {
    int linesToPrint;
    if (argv[1][0] == '-') {
        if (argv[1][1] == 'n') {
            linesToPrint = atoi(argv[2]);
        }
        else {
            linesToPrint = DEFAULT_LINES;
        } 
    }
    int i = 0;
    char line[MAX_LINE_LENGTH];
    char *lines[MAX_LINES];
    // TODO: get nextline from file
    while (mygetline(line, MAX_LINE_LENGTH)) {
        strcpy(lines[i++], line);
    }
    tail(linesToPrint, lines, i);
}

void tail(int linesToPrint, char *lines[], int numLines) {
    for (int i = 0; i < numLines; i++) {
        if (i >= numLines - linesToPrint) {
            printf("%s\n", lines[i]);
        }
    }
}

int mygetline(char *dest, int limit) {
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        *(dest + i) = c;
    }
    if (i == 0) {
        dest[0] = '\0';
        return 0;
    }
    else {
        *(dest + i++) = '\n';
        *(dest + i) = '\0';
        return 1;
    }
}