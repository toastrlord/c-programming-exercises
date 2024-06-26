#include <stdio.h>

int setbits(int x, int p, int n, int y);
int sign(int x);
void printBinary(int x, int minBits);

main() {
  int x = 4;
  int y = 3;
  int n = 3;
  int p = 0; 
  printBinary(x, 8);
  printBinary(y, 8);
  setbits(x, n, p, y);
  //printf("%d\n", setbits(x, n, p, y));
}

int setbits(int x, int p, int n, int y) {
  int xMask = ~((~(~0 << n))) << (p + 1 - n);
  //printf("xMask: ");
  printBinary(xMask, 8);
  int masked = x & xMask;
  int yMask = (~(~0 << n) & y) << (p+ 1 - n);
  return x ^ y;
}

void printBinary(int x, int minBits) {
  int sgn = sign(x);
  int numBits, res;
  res = x;
  numBits = 0;
  while ((x >> numBits) >= 0) {
    numBits++;
  }
  numBits--;
  printf("Num bits in %d: %d\n", x, numBits);
  if (minBits > numBits) {
    numBits = minBits;
  }
  for (int i = numBits; i > 0; i--) {
    int bitIsOn = (x >> i) & ~0;
    if (bitIsOn > 0) {
      putchar('1');
    } else {
      putchar('0');
    }
  }
  putchar('\n');
}

int sign(int x) {
  if (x > 0) {
    return 1;
  }
  if (x < 0) {
    return -1;
  }
  return 0;
}