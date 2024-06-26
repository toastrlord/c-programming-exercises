// exercise 1-9: write a program to copy its input to its output replacing each string of one or more blanks by a single blank
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