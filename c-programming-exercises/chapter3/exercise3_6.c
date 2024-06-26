#include <stdio.h>

void reverse(char s[]);
int itoa(int n, char s[], int minWidth);

main() {
    char s[1000];
    itoa(-5, s, 5);
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

int itoa(int n, char s[], int minWidth) {
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (abs(n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    while (i < minWidth) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}