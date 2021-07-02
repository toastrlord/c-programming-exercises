#include <stdio.h>

#define MAX_BUFFER 1000
#define TAB_WIDTH 7

int mygetline(char line[], int limit);
void entab(char to[], char from[]);

main() {
    char line[MAX_BUFFER];
    char entabbed[MAX_BUFFER];
    while (mygetline(line, MAX_BUFFER) > 0) {
        entab(entabbed, line);
        printf("%s", line);
        printf("%s", entabbed);
    }
}

int mygetline(char line[], int limit) {
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

void entab(char to[], char from[]) {
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
                int tabsToInsert = numSpaces / TAB_WIDTH;
                int spacesToInsert = numSpaces % TAB_WIDTH;
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