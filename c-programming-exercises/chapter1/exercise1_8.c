// exercise 1-8: write a program to count blanks, tabs and newlines
#include <stdio.h>

main() {
    char c;
    int count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            ++count;
        }
    }
    printf("Number of tabs, spaces and newlines in input: %d\n", count);
}