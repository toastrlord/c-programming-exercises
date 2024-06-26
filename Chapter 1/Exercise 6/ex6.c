#include <stdio.h>

main() {
  int c;
  printf("5 != EOF? %d\n", (c = 5) != EOF);
  printf("EOF != EOF? %d\n", (c = EOF) != EOF);
}