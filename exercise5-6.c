#include <stdio.h>

void getline(char *, int);

main() {

}

void getline(char *dest, int limit) {
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        *(dest + i) = c;
    }
    *(dest + i++) = '\n';
    *(dest + i) = '\0';
}