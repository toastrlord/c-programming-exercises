#include <stdio.h>

char lower(char c);

main() {
    char testString[] = "AFZaqz123";
    printf("%s\n", testString);
    for (int i = 0; testString[i] != '\0'; ++i) {
        printf("%c", lower(testString[i]));
    }
    printf("\n");
}

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}