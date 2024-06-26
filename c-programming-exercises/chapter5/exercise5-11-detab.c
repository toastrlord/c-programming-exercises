#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_WIDTH 7
#define MAX_LINE 100

char input[MAX_LINE];
char output[MAX_LINE];

void detab(char *, char *, int);

main(int argc, char *arv[]) {
    int i = 1;
    if (argc != 3) {
        printf("Usage: detab inputFile outputFile\n");
        return;
    }
    while (input = getline()) {
        if (i == argc) {
            entab(input, output, atoi(argv[i]));
        }  
        else {
            entab(input, output, DEFAULT_TAB_WIDTH);
        }
        printf("%s\n", output);
    }
}

void detab(char to[], char from[], int tabWidth) {
    int i, j, c;
    i = 0;
    j = 0;
    while ((c = from[i]) != '\0') {
        if (c == '\t') {
            int numSpaces = tabWidth - (j % tabWidth);
            for (int k = 0; k <= numSpaces; ++k) {
                to[j + k] = ' ';
            }
            j += numSpaces;
        }
        else {
            to[j] = from[i];
            ++j;
        }
        ++i;
    }
    to[j] = '\0';
}