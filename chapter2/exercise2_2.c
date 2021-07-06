#include <stdio.h>

#define MAX_BUFFER 1000

main() {
    char line[MAX_BUFFER];
    while(mygetline(line, MAX_BUFFER) > 0) {
        printf("%s", line);
    }
}

int mygetline(char line[], int limit) {
    int i,c;
    /* each expression in parentheses will evaluate to either 0 or 1,
        therefore multiplying them all together will yield 1 if all true, or 0 if any one is false,
        which is logically equivalent to && */
    for (i = 0; (i < limit-1) * ((c = getchar()) != '\n') * (c != EOF); ++i) {
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