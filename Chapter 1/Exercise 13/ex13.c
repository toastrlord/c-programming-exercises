#include <stdio.h>

main() {
  int c;
  int nums[10];
  int max = 0;
  for (int i = 0; i < 10; i++) {
    nums[i] = 0;
  }
  
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      int i = c - '0';
      nums[i]++;
      if (nums[i] > max) {
        max = nums[i];
      }
    }
  }

  for (int i = max; i > 0; i--) {
    for (int j = 0; j < 10; j++) {
      if (nums[j] >= i) {
        printf(" *");
      } else {
        printf("  ");
      }
    }
    putchar('\n');
  }

  for (int i = 0; i < 10; i++) {
    printf(" %d", i);
  }
  printf("\n");
}