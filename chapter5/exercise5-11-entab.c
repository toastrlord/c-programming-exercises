#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_WIDTH 7
#define MAX_LINE 100

char input[MAX_LINE];
char output[MAX_LINE];

void entab(char *, char *, int);

main(int argc, char *argv[]) {
    int i = 1;
    while (getline(input)) {
        if (i == argc) {
            entab(input, output, atoi(argv[i]));
        }  
        else {
            entab(input, output, DEFAULT_TAB_WIDTH);
        }
        printf("%s\n", output);
    }
}

void entab(char to[], char from[], int tabWidth) {
    int i, j, c, numSpaces;
    i = 0;
    j = 0;
    numSpaces = 0;
    while ((c = from[i]) != '\0') {
        if (c == ' ') {
            ++numSpaces;
        }
        else {
            if (numSpaces > 0) {
                // insert necessary tabs and spaces
                int tabsToInsert = numSpaces / tabWidth;
                int spacesToInsert = numSpaces % tabWidth;
                for (int k = 0; k < tabsToInsert; ++k) {
                    to[j] = '\t';
                    ++j;
                }
                for (int k = 0; k < spacesToInsert; ++k) {
                    to[j] = ' ';
                    ++j;
                }
                printf("Total spaces: %d, tabs to insert: %d, spaces to insert %d\n", numSpaces, tabsToInsert, spacesToInsert);
                numSpaces = 0;
            }
            to[j] = from[i];
            ++j;
        }
        ++i;
    }
    to[j] = '\0';
}