#include <stdio.h>

main() {
  printf("Deg F\tDeg C\n");
  int fahr, lower, step, upper;
  lower = 0;
  step = 20;
  upper = 300;
  for (fahr = upper; fahr >= lower; fahr = fahr - step) {
    printf("%5d\t%5.1f\n", fahr, 5.0/9.0 * (fahr - 32.0));
  } 
}