#include <stdio.h>

// exercise 4_9- handle a pushed back EOF character

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int eof_reached = 0;

int getch(void) {
    if (eof_reached) {
        return EOF;
    }
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) {
    if (c == EOF) {
        eof_reached = 1;
    }
    if (bufp < BUFSIZE) {
        buf[bufp++] = c;
    }
    else {
        printf("error: character buffer full\n");
    }
}