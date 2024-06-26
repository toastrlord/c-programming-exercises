// exercise 1-12: write a program that prints its input one word per line
#include <stdio.h>

// Print input one word per line

main() {
    char c;
    int hasWord = 0;
    
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c =='\n') {
            if (hasWord) {
                putchar('\n');
                hasWord = 0;
            }
        }
        else {
            hasWord = 1;
            putchar(c);
        }
    }
}