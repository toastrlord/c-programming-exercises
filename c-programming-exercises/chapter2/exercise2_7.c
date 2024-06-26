#include <stdio.h>

int invert(int x, int p, int n);

main() {
    printf("%d\n", invert(25, 2, 3));
}

int invert(int x, int p, int n) {
    int bitsToInvertMask = ~((~0 << p + 1) | ~(~0 << p - n + 1));
    int bitsToInvert = x & bitsToInvertMask;
    int invertedBits = ~bitsToInvert & bitsToInvertMask;

    return (x & ~bitsToInvertMask) | invertedBits;
}