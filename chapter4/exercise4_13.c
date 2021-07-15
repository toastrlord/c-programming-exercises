#include <stdio.h>

void inner(char[], int);
void reverse(char[]);

main() {
    char str[] = "1";
    reverse(str);
    printf("%s\n", str);
}

// done in place, but not very efficient, since we need to traverse from j to i every time
void inner(char str[], int i) {
    char c = str[i];
    if (c == '\0') {
        return;
    }
    else {
        for (int j = i; j > 0; j--) {
            str[j] = str[j-1];
        }
        str[0] = c;
        inner(str, i + 1);
    }
}

void reverse(char str[]) {
    inner(str, 0);
}