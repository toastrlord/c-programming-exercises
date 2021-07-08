#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

main() {
    char s[1000];
    itob(35, s, 16);
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

// very similar to itoa, except replace /=10 and %10 with more general 'b' variable
void itob(int n, char s[], int b) {
    int i, sign;
    sign = n;
    i = 0;
    do {
        int remainder = abs(n % b);
        // need to differentiate between 0-9 and values greater than 10, since 'A' doesn't come immediately after '9'
        int digit = remainder < 10 ? remainder + '0' : (remainder - 10) + 'A';
        s[i++] = digit;
    } while (abs(n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}