#include <stdio.h>

void mystrncpy(char *, char *, int);
void mystrncat(char *, char *, int);
int mystrncmp(char *, char *, int);

main() {
    char str1[50] = "abdef";
    char str2[50] = "defghi";
    
    printf("%d\n", mystrncmp(str1, str2, 2));
}

void mystrncpy(char *s, char *t, int n) {
    int i = 0;
    while (i < n && (*(s+i) = *(t+i))) {
        i++;
    }
    *(s+i) = '\0';
}

void mystrncat(char *s, char *t, int n) {
    int i = 0;
    while (*s) {
        s++;
    }
    while(i < n && (*s++ = *t++)) {
        i++;
    }
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n) {
    int i = 0;
    // FIXME!!!
    while (*s++ != *t && *s) {
        while (i < n && *s++ == *t++) {
            i++;
            if (*s =='\0' && i == n) {
                return 1;
            }
        }
    }
    return 0;
}