#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

main() {
    char s[1000];
    itoa(INT_MIN, s);
    printf("%s\n", s);
}

void reverse(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;
    for (int j = i; j > i / 2; --j) {
        char temp = s[j];
        s[j] = s[i - j];
        s[i - j] = temp;
    }
}

/*  the original version of itoa will fail for the INT_MIN, since INT_MAX is abs(INT_MIN) - 1
    instead, use absolute value of the modulus, instead of setting n = -n */
void itoa(int n, char s[]) {
    int i, sign;
    sign = n;
    /*if ((sign = n) < 0) {
        printf("%d\n", n);
        n = -n;
        printf("%d\n", n);
    }*/
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (abs(n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}