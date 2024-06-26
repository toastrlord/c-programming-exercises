// a bit confused by this one, so skipped

#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void mycopy(char to[], char from[]);

main() {
  int len, max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      mycopy(longest, line);
    }
  }
  if (max > 0) {
    printf("%s", longest);
  }
}

int mygetline(char line[], int maxline) {
  int i, c;
  i = 0;
  while ((c = getchar()) != EOF && c != '\n' && i < maxline - 1) {
    line[i] = c;
    ++i;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void mycopy(char to[], char from[]) {
  int i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}