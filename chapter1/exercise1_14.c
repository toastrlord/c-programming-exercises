// Write a program to print a histogram of the frequencies of different characters in its input
#include <stdio.h>

#define CHARSIZE 256

// create a histogram of all the characters present in the input
main() {
    int c;
    int frequencies[CHARSIZE];
    for (int i = 0; i < CHARSIZE; i++) {
        frequencies[i] = 0;
    }
    while((c = getchar()) != EOF) {
        ++frequencies[c];
    }

    int max = 0;
    for (int i = 0; i < CHARSIZE; i++) {
        if (frequencies[i] > max) {
            max = frequencies[i];
        }
    }
    int divisions = 10;
    int increment = 1;
    if (max > divisions) {
        increment = max / divisions;
    }
    for (int i = max; i >= 1; i -= increment) {
        printf("%2d", i);
        for (int j = 0; j < CHARSIZE; j++) {
            if (frequencies[j] == 0) {
                continue;
            }
            if (frequencies[j] >= i) {
                printf(" *");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < CHARSIZE; i++) {
        if (frequencies[i] > 0) {
            switch (i) {
                case '\n':
                    printf("\\n");
                    break;
                case '\t':
                    printf("\\t");
                    break;
                case '\r':
                    printf("\\r");
                    break;
                default:
                    printf("%2c", i);
            }
        }
    }
    printf("\n");
}