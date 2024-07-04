#include <stdio.h>

int invert(int x, int p, int n);

int main() {
  printf("%d\n", invert(70, 4, 3));
}

int invert(int x, int p, int n) {
  // get a mask such that values in p to p - n - 1 are 1's, 0's otherwise
  // then XOR with x, this will invert any of the bits in those locations
  int mask = ~(~0 << n) << (p - n + 1);
  printf("Mask: %d\n", mask);
  return x ^ mask;
}
