#include <stdio.h>
#include <string.h>

void mygetline(char *, int);
int myatoi(char *);
void myitoa(int, char *);

main() {

}

void mygetline(char *dest, int limit) {
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        *(dest + i) = c;
    }
    *(dest + i++) = '\n';
    *(dest + i) = '\0';
}

int myatoi(char *str) {
    while(isspace(*str)) {
        str++;
    }
    int sign = *str == '-' ? -1 : 1;
    if (*str == '+' || *str == '-') {
        str++;
    }
    int result = 0;
    while(*str >= '0' && *str <= '9') {
        result = 10 * result + (*str - '0');
        str++;
    }
    return result * sign;
}

void myitoa(int number, char *dest) {
    char *start = dest;
    while (number > 0) {
        *dest = number % 10;
        dest ++;
        number /= 10;
    }
    *dest = '\0';
    reverse(start);
}