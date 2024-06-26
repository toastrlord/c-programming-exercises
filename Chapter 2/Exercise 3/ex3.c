#include <stdio.h>

#define MAXLINE 2000

int mygetline(char line[], int max);
int htoi(char str[]);
int mypow(int base, int n);

main() {
  char line[MAXLINE];
  int len;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    printf("%d\n", htoi(line));
  }
}

int mygetline(char line[], int max) {
  int i, c;
  for (i = 0; i < max -1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';

  return i;
}

int htoi(char str[]) {
  int i, c, len, result;
  len = result = 0;
  int minLen = 0;
  for (i = 0; (c = str[i]) != '\0' && c != '\n'; ++i) {
    len++;
  }
  if (len > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
    len = len - 2;
    minLen = 2;
  }
  
  int exponent = 0;
  for (i = minLen + len - 1; i >= minLen; --i) {
    c = str[i];
    int digit;
    if (c >= 'a' && c <= 'f') {
      digit = 10 + c - 'a';
    }
    if (c >= 'A' && c <= 'F') {
      digit = 10 + c - 'A';
    }
    if (c >= '0' && c <= '9') {
      digit = c - '0';
    }
    int addition = digit * mypow(16, exponent);
    result = result + addition;
    exponent++;
  }
  return result;
}

int mypow(int base, int n) {
  int result = 1;
  for (int i = 0; i < n; ++i) {
    result = result * base;
  }

  return result;
}