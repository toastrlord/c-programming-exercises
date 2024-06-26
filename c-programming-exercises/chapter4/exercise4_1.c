#include <stdio.h>

int strrindex(char s[], char t);

main() {
    char str[] = "abcdefghijkaz";
    printf("%d\n", strrindex(str, 'a'));
}

int strrindex(char s[], char t) {
    int i = 0;
    int occurrence = -1;
    while (s[i] != '\0') {
        if (s[i] == t) {
            occurrence = i;
        }
        ++i;
    }

    return occurrence;
}