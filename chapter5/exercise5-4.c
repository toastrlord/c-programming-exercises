#include <stdio.h>

int strend(char *, char *);

main() {
    char *str1 = "abcdef";
    char *str2 = "def";
    char *str3 = "cde";
    printf("%s ends with %s: %d\n", str1, str2, strend(str1, str2));
    printf("%s ends with %s: %d\n", str1, str3, strend(str1, str3));
    printf("%s ends with %s: %d\n", str2, str3, strend(str2, str3));
}

int strend(char *s, char *t) {
    while (*++s != *t && *s);
    while (*s++ == *t++) {
        if (*s == '\0' && *t == '\0') {
            return 1;
        }
    }
    return 0;
}