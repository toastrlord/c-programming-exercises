#include <stdio.h>

#define MAXLINE 2000

int mygetline(char s[], int limit);
//void mycopy(char to[], char from[]);

main() {
  char line[MAXLINE];
  int len = 0;
  int limit = 80;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len > 80) {
      printf("%s", line);
    }
  }
}

int mygetline(char line[], int limit) {
  int i, c;
  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}