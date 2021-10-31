// exercise 1-13: write a program to print a histogram of the lengths of words in its input. A horizontal histogram is easier- vertical is more challenging
#include <stdio.h>

// print a histogram of the lengths of words in the input
main() {
    int i;
    int c;
    int length = 11;
    int currentWordLength = 0;
    int wordLengths[length];
    for (i = 0; i < length; i++) {
        wordLengths[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (currentWordLength < length) {
                ++wordLengths[currentWordLength];
            }
            currentWordLength = 0;
        }
        else {
            ++currentWordLength;
        }
    }
    int max = 0;
    for (i = 0; i < length; i++) {
        if (wordLengths[i] > max) {
            max = wordLengths[i];
        }
    }
    int increment = 1;
    int divisions = 10;
    if (max > 10) {
        increment = max / divisions;
    }
    for (i = max; i > 0; i -= increment) {
        printf("%2d ", i);
        for (int j = 0; j < length; j++) {
            if (wordLengths[j] >= i) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("   ");
    for (int i = 0; i < length; i++) {
        printf("%1d ", i);
    }
    printf("\n");
}