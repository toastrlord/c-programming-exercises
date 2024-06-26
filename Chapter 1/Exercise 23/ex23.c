#include <stdio.h>

#define MAXLINE 2000
#define NO_COMMENT 0
#define MULTILINE_COMMENT 1
#define SINGLELINE_COMMENT 2

int mygetline(char line[], int max);
void removeComments(char in[], char out[]);

main() {
  char in[MAXLINE];
  char out[MAXLINE];
  int c, len;
  while ((len = mygetline(in, MAXLINE)) > 0) {
    removeComments(in, out);
    printf("%s", out);
  }
}

int mygetline(char line[], int max) {
  int i, c;
  for (i = 0; i < max -1 && (c = getchar()) != EOF; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';
  return i;
}

void removeComments(char in[], char out[]) {
  int i, j, currentChar, nextChar, state, linelength;
  state = NO_COMMENT;
  j = linelength = 0;
  for (i = 0; (currentChar = in[i]) != EOF && currentChar != '\0'; ++i) {
    nextChar = in[i+1];
    if (currentChar == '/') {
      if (nextChar == '/' && state != MULTILINE_COMMENT) {
        state = SINGLELINE_COMMENT;
        ++i;
        continue;
      }
      if (nextChar == '*') {
        state = MULTILINE_COMMENT;
        ++i;
        continue;
      }
    }
    if (currentChar == '*') {
      if (nextChar == '/') {
        state = NO_COMMENT;
        ++i;
        continue;
      }
    }
    if (state == NO_COMMENT) {
      out[j] = in[i];
      ++j;
      ++linelength;
    }
    else if (currentChar == '\n') {
      if (state == SINGLELINE_COMMENT) {
        state = NO_COMMENT;
      }
      if (linelength == 0) {
          linelength = 0;
          continue;
      }
      out[j] = '\n';
      ++j;
      linelength = 0;
    }
  }
  out[j] = '\0';
}