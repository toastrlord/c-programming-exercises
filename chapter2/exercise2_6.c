#include <stdio.h>

void printSetBitsResult(int x, int p, int n, int y);
int setbits(int x, int p, int n, int y);

main() {
    printSetBitsResult(15, 3, 2, 9);
    printSetBitsResult(8, 2, 1, 1);
}

void printSetBitsResult(int x, int p, int n, int y) {
    printf("x=%d, p=%d, y=%d, n=%d, result=%d\n", x, p, n, y, setbits(x, p, n, y));
}

int setbits(int x, int p, int n, int y) {
    int rightMost = y & ~(~0 << n);
    int yMask = rightMost << (p - n + 1);
    int turnOff = (~0 << p + 1) | ~(~0 << (p - n + 1));
    return yMask | (x & turnOff);
}