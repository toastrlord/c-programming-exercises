#include <stdio.h>

main() {
  float fahr, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;
  printf("Deg F\tDeg C\n");
  while (fahr <= upper) {
    celsius = 5.0 * (fahr-32.0) / 9.0;
    printf("%5.0f\t%5.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  printf("~~~~~~~~~~~~~\n");
  printf("Deg C\tDeg F\n");
  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0/5.0 * celsius) + 32.0;
    printf("%5.0f\t%5.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}