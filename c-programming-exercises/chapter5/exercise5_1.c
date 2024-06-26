#include <ctype.h>
#include <stdio.h>

#define MAX_BUFFER 100

char buffer[MAX_BUFFER];
int bufferIndex = 0;
int getch(void);
void ungetch(int);
int getint(int *);

main() {
    int num[100];
    printf("%d\n", getint(num));
}

int getch(void) {
    if (bufferIndex > 0) {
        return buffer[--bufferIndex];
    }
    else {
        return getchar();
    }
}

void ungetch(int n) {
    if (bufferIndex >= MAX_BUFFER) {
        printf("ungetch: exceeded buffer size\n");
    }
    else {
        buffer[bufferIndex++] = n;
    }
}

// as written, getint treats a + or - sign not followed by a digit as a valid representation of zero.
// fix it to push such a character back onto the input
int getint(int *pn) {
    int c, sign;
    while(isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        char sign = c;
        c = getch();
        // modified for exercise 5-1
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(sign);
            return 0;
        }
        // end of exercise 5-1 modifications
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}