#include <stdio.h>

#define swap(t,x,y) t y, t x

int subtract(int, int);
int reverseSubtract(int, int);

main() {
    printf("subtract: %d\n", subtract(2, 9));
    printf("reverse subtract: %d\n", reverseSubtract(2, 9));
}

int subtract(int x, int y) {
    return x - y;
}

int reverseSubtract(swap(int, x, y)) {
    return x - y;
}