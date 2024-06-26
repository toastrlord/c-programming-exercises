#include <stdio.h>

int mystrlen(char str[]);
int htoi(char str[]);

main() {
    char hex[] = "0x2f";
    printf("%s = %d\n", hex, htoi(hex));
}

int mystrlen(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; ++i);
    return i;
}

double mypow(double x, int y) {
    double result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

// convert numerics AND hex chars to integer
int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return c;
}

int htoi(char str[]) {
    int i,c,len,result;
    i = 0;
    result = 0;
    len = mystrlen(str);
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        i += 2;
    }
    for (int j = len - 1; j >= i; --j) {
        int num = ctoi(str[j]);
        result += num * mypow(16, (len - 1) - j);
    }

    return result;
}