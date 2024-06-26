#include <stdio.h>

main() {
  int c;
  double blank, tab, newline;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blank;
    }
    if (c == '\t') {
      ++tab;
    }
    if (c == '\n') {
      ++newline;
    }
  }
  printf("Blanks\tTabs\tNewlines\n");
  printf("%.0f\t%.0f\t%.0f\n", blank, tab, newline);
}