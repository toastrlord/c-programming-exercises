// exercise 1-10: write a program to copy its input to its output, replacing each tab by \t, backspace by \b, and each backslash by \\

#include <stdio.h>

main() {
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\t");
        }
        else if (c == '\b') {
            printf("\b");
        }
        else if (c == '\\') {
            printf("\\");
        }
        else if (c == '\n') {
            printf("\n");
        }
        else {
            putchar(c);
        }
    }
}