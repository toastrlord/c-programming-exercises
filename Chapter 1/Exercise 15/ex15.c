#include <stdio.h>

float fToC(float f);
float cToF(float c);

main() {
  float fahr, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;
  printf("Deg F\tDeg C\n");
  while (fahr <= upper) {
    printf("%5.0f\t%5.1f\n", fahr, fToC(fahr));
    fahr = fahr + step;
  }
  printf("~~~~~~~~~~~~~\n");
  printf("Deg C\tDeg F\n");
  celsius = lower;
  while (celsius <= upper) {
    printf("%5.0f\t%5.1f\n", celsius, cToF(celsius));
    celsius = celsius + step;
  }
}

float fToC(float f) {
  return 5.0 * (f - 32.0) / 9.0;
}

float cToF(float c) {
  return (9.0 / 5.0 * c) + 32.0;
}