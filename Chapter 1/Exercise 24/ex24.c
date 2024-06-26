#include <stdio.h>

#define MAXLINE 2000
#define OPEN 1
#define CLOSED 0
#define OPEN_PAREN 0
#define CLOSE_PAREN 1
#define TRUE 1
#define FALSE 0

int mygetline(char line[], int max);
int getIndex(char c);
int isOpening(char c);
void syntaxCheck(char input[]);
void printSyntaxError(char line[], int start, int location);
void bracketsBalanced(int counts[]);

main() {
  char in[MAXLINE];
  int len;
  while ((len = mygetline(in, MAXLINE))) {
    syntaxCheck(in);
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

void syntaxCheck(char input[]) {
  int i,j,c, bracketState, parenState, curlState, lineStart;
  int counts[6];
  for (int i = 0; i < 6; ++i) {
    counts[i] = 0;
  }
  bracketState = parenState = curlState = CLOSED;
  int lineNum = 1;
  lineStart = 0;
  for (i = 0; (c = input[i]) != '\0'; ++i) {
    if (c == '\n') {
      lineNum++;
      lineStart = i + 1;
      continue;
    }
    j = getIndex(c);
    if (j >= 0) {
      counts[j]++;
      if (isOpening(c) == FALSE && counts[j-1] < counts[j]) {
        printf("Unexpected token %c, line %d\n", c, lineNum);
        printSyntaxError(input, lineStart, i);
      }
    }
  }
  bracketsBalanced(counts);
}

int getIndex(char c) {
  if (c == '(') {
    return 0;
  }
  if (c == ')') {
    return 1;
  }
  if (c == '{') {
    return 2;
  }
  if (c == '}') {
    return 3;
  }
  if (c == '[') {
    return 4;
  }
  if (c == ']') {
    return 5;
  }
  return -1;
}

int isOpening(char c) {
  if (c== '(' || c == '{' || c == '[') {
    return TRUE;
  }
  return FALSE;
}

void bracketsBalanced(int counts[]) {
  for (int i = 0; i < 6; i += 2) {
    if (counts[i] != counts[i + 1]) {
      char c;
      if (i == 0)
        c = ')';
      if (i == 2) 
        c = '{';
      if (i == 4)
        c = '[';
      printf("Expected %c\n", c);
    }
  }
}

void printSyntaxError(char line[], int start, int location) {
  int i, c;
  for (i = start; (c = line[i]) != '\n' && c != EOF; ++i) {
    putchar(line[i]);
  }
  putchar('\n');
  for (i = start; i < location; ++i) {
    putchar(' ');
  }
  printf("^\n");
}