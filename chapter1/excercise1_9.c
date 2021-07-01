#include <stdio.h>

main() {
    char c;
    int isSpace = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            isSpace = 1;
        }
        else if (c != ' ' && isSpace) {
            isSpace = 0;
            putchar(' ');
            putchar(c);
        }
        else {
            putchar(c);
        }
    }
}