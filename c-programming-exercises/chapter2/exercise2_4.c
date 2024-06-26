#include <stdio.h>

void squeeze(char s1[], char s2[]);

main() {
    char s1[] = "abcdef";
    char s2[] = "b12a34a56fg";
    squeeze(s1, s2);
    printf("%s\n", s2);
}

void squeeze(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                int k = j;
                while(s2[k] != '\0') {
                    s2[k] = s2[k+1];
                    k++;
                }
            }
        }
    }
}