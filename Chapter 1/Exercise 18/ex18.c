#include <stdio.h>

#define MAXLINE 2000

#define IN_BLANK 0
#define OUT_BLANK 1

int mygetline(char line[], int maxline);

main() {
  int len, state;
  state = OUT_BLANK;
  char line[MAXLINE];
  while ((len = mygetline(line, MAXLINE)) > 0) {
    int i, firstBlank;
    firstBlank = 0;
    char currentChar;
    for (i = 0; i < MAXLINE - 1 && line[i] && (currentChar = line[i]) != '\0' && currentChar != '\n'; ++i) {
      if (currentChar == ' ' || currentChar == '\t') {
        if (state == OUT_BLANK) {
          firstBlank = i;
          state = IN_BLANK;
        }
      } else {
        state = OUT_BLANK;
      }
    }
    if (i != 1) {
      if (state == IN_BLANK && firstBlank != 0) {
        line[firstBlank] = '\n';
        line[firstBlank + 1] = '\0';
      }
      if (state == IN_BLANK && firstBlank == 0) {
        line[0] = '\0';
      }
      printf("%s", line);
    }
  }
}

int mygetline(char line[], int maxline) {
  int i, c;
  for (i = 0; i < maxline -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}