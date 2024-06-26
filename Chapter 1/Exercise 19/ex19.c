#include <stdio.h>

#define MAXLINE 2000

int mygetline(char line[], int max);
void reverse(char line[]);

main() {
  char line[MAXLINE];
  int len;
  while ((len = mygetline(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }
}

int mygetline(char line[], int max) {
  int i,c;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void reverse(char string[]) {
  int endpoint = 0;
  while (string[endpoint] != '\0' && string[endpoint] != '\n') {
    ++endpoint;
  }
  endpoint--;
  int i = 0;
  for (int j = endpoint; j > (endpoint) / 2; --j) {
    char temp = string[j];
    string[j] = string[i];
    string[i] = temp;
    ++i;
  }
}