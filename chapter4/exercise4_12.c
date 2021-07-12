#include <stdio.h>

int itoa(int, char[]);
int inner(int, char[], int);

main() {
    char s[1000];
    itoa(5237, s);
    printf("%s\n", s);
}

int itoa(int num, char s[]) {
    int len = inner(num, s, 0);
    printf("len %d\n", len);
    s[len+1] = '\0';
}

int inner(int num, char s[], int i) {
    if (num < 0) {
        num = -num;
        s[i++] = '-';
    }
    if (num / 10) {
        //  more than one digit to go!
        int j = inner(num / 10, s, i + 1);
        s[j - i] = num % 10 + '0';
        printf("%d, %d\n", i, j);
        return j;
    }
    else {
        // terminate!
        s[0] = num % 10 + '0';
    }
    return i;
}