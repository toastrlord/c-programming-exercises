#include <stdio.h>

#define MAXLINE 2000

void detab(char in[], char out[], int tabWidth);
int mygetline(char line[], int max);


main() {
  char line[MAXLINE];
  char outLine[MAXLINE];
  int len;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    detab(line, outLine, 4);
    printf("%s", outLine);
  }
}

int mygetline(char line[], int max) {
  int i, c;
  for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}

void detab(char in[], char out[], int tabWidth) {
  int i, j, c;
  j = 0;
  for (int i = 0; (c = in[i]) != '\0'; i++) {
    if (c != '\t') {
      out[j] = in[i];
      j++;
    } else {
      int nextTab = tabWidth;
      while (nextTab <= j)
        nextTab = nextTab + tabWidth;
      while (j < nextTab) {
        out[j] = ' ';
        j++;
      }
    }
  }
  out[j] = '\0';
}