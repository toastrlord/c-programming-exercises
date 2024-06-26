#include <stdio.h>

#define LINEMAX 2000

int mygetline(char line[], int max);

void detab(char in[], char out[], int tabSize);

main() {
  int len;
  char inLine[LINEMAX];
  char outLine[LINEMAX];
  while ((len = mygetline(inLine, LINEMAX)) > 0) {
    detab(inLine, outLine, 8);
    printf("%s", outLine);
  }
}

int mygetline(char line[], int max) {
  int i, c;
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

void detab(char in[], char out[], int tabSize) {
  int i, c, j, nextEnd;
  i = j = 0;
  while ((c = in[i]) != '\0') {
    if (c != ' ') {
      out[j] = in[i];
      ++j;
      ++i;
    } else {
      int start = i;
      while (in[i] == ' ')
        ++i;
      nextEnd = i - 1;
      int numTabs, numSpaces;
      numTabs = numSpaces = 0;
      int nextTabStop = (start / tabSize + 1) * tabSize;
      // first, count how many tabstops are between start and end
      while (nextTabStop <= nextEnd) {
        nextTabStop += tabSize;
        numTabs++;
      }
      if (numTabs == 0) {
        numSpaces = nextEnd - start + 1;
      } else {
        numSpaces = nextEnd - (nextTabStop - tabSize) + 1;
      }
      for (int k = 0; k < numTabs; k++) {
        out[j] = '\t';
        ++j;
      }
      for (int k = 0; k < numSpaces; k++) {
        out[j] = ' ';
        ++j;
      }
    }
  }
  out[j] = '\0';
}