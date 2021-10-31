// exercise 1-23: Write a program to remove all comments from a C program. Dont forget to handle quoted strings and character constants properly. C comments do not nest.
#include <stdio.h>

#define MAX_BUFFER 1000

int commenting = 0;
int mygetline(char line[], int limit); 
int strequal(char str1[], char str2[]);
void uncomment(char to[], char from[]); 

main() {
    char line[MAX_BUFFER];
    char uncommented[MAX_BUFFER];
    while (mygetline(line, MAX_BUFFER) > 0) {
        uncomment(uncommented, line);
        printf("%s", uncommented);
    }
}

int mygetline(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (i == 0) {
        return 0;
    }
    line[i] = '\n';
    ++i;
    line[i] = '\0';
    return i;
}

int strequal(char str1[], char str2[]) {
    int i, j;
    i = 0;
    j = 0;
    while (str1[i] != '\0' && str2[j] != '\0') {
        if (str1[i] != str2[j]) {
            return 0;
        }
        ++i;
        ++j;
    }
    if (str1[i] == '\0' && str2[j] == '\0') {
        return 1;
    }
    return 0;
}

// presumes that each string consists of only one line
void uncomment(char to[], char from[]) {
    int j, c;
    char substr[2];
    j = 0;
    for (int i = 0; (substr[0] = from[i]) != '\0'; ++i) {
        substr[1] = from[i + 1];
        if (strequal(substr, "//")) {
            break;
        }
        else if (strequal(substr, "/*")) {
            commenting = 1;
            ++i;
        }
        else if (strequal(substr, "*/")) {
            commenting = 0;
            ++i;
        }
        else {
            if (!commenting) {
                to[j] = from[i];
                ++j;
            }
        }
    }
    if (to[j] != '\n') {
        to[j] = '\n';
        ++j;
    }
    to[j] = '\0';
}