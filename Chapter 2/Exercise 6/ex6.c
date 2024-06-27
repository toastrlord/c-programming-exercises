#include <stdio.h>

/*
  Exercise 2-6:
  Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits
  unchanged
*/

int setbits(int x, int p, int n, int y);
int sign(int x);
void printBinary(int x, int minBits);

main() {
  int x = 23;
  int y = 106;
  printf("%d\n", setbits(x, 3, 3, y));
}

int setbits(int x, int p, int n, int y) {
  int yMask = ~(~0 << n);
  int xMask = ~((~(~0 << n)) << (p + 1 - n));
  int xMasked = x & xMask;
  int yMasked = (y & yMask) << (p + 1 - n);
  return x ^ y;
}