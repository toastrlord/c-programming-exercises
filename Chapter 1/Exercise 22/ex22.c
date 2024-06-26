#include <stdio.h>

#define MAXLINE 2000
#define FOUNDSPACE 1
#define NOSPACE 0

int mygetline(char line[], int max);
void fold (char in[], char out[], int lineSize);


main() {
  char in[MAXLINE];
  char out[MAXLINE];
  int len;
  while ((len = mygetline(in, MAXLINE)) > 0) {
    fold(in, out, 20);
    printf("%s", out);
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

void fold(char in[], char out[], int linesize) {
  // go through the input text, 
  int i, j, c, lastSpace, state;
  j = lastSpace = 0;
  int count = 1;
  int chunkStart = 0;
  for (int i = 0; (c = in[i]) != EOF; ++i) {
    if (c == ' ') {
      state = FOUNDSPACE;
      lastSpace = i;
    }
    // if we found a space, go from chunk start to the space
    // however, we need to see if we NEED to go to the space, or if we can go all the way to the end
    // otherwise, go from chunk start to count
    if (count % linesize == 0 && count > 0) {
      int end;
      if (state == FOUNDSPACE && c != ' ') {
        end = lastSpace;
      } else {
        end = i;
      }
      for (int k = chunkStart; k < end; ++k) {
        out[j] = in[k];
        ++j;
      }
      out[j] = '\n';
      ++j;
      if (state = FOUNDSPACE) {
        // prune space from next line
        i = end + 1;
      } else {
        i = end;
      }
      state = NOSPACE;
      count = 1;
      chunkStart = i;
    } else {
      count++;
    }
  }
  out[j] = '\0';
}