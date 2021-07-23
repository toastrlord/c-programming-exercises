#include <stdio.h>

void mystrcat(char *, char *);

main() {
    char str1[50] = "abc";
    char str2[50] = "def";
    mystrcat(str1, str2);
    printf("%s\n", str1);
}

void mystrcat(char *s, char *t) {
    while(*s) {
        s++;
    }
    while(*s++ = *t++);
    *s = '\0';
}