#include <stdio.h>

void expand(char s1[], char s2[]);

main() {
    char s1[] = "A-H0-4-7-z";
    char s2[1000];
    expand(s1, s2);
}

void expand(char s1[], char s2[]) {
    int lowbound, hibound;
    int i = 0;
    int j = 0;
    while (s1[i] != '\0') {
        if (s1[i] == '-') {
            hibound = s1[i+1];
            i = i + 2;
            while (lowbound <= hibound) {
                s2[j] = lowbound;
                j++;
                lowbound++;
            }
        }
        else {
            lowbound = s1[i];
            hibound = s1[i+2];
            i = i + 3;
            while (lowbound <= hibound) {
                s2[j] = lowbound;
                j++;
                lowbound++;
            }
        }
    }
    
    s2[j] = '\0';
    printf("%s\n", s2);
}