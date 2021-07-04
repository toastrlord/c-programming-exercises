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
        printf("uncomment\n");
        uncomment(uncommented, line);
        printf("%s\n", uncommented);
    }
}

int mygetline(char line[], int limit) {
    printf("getting line\n");
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
        printf("%c", c);
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
    to[j] = '\0';
}