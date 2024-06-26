#include <stdio.h>

void squeeze(char s1[], char s2[]);

main() {
  char string1[] = "Hello world!";
  char string2[] = "lro";
  squeeze(string1, string2);
  printf("%s\n", string1);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k, c1, c2, found;
  k = found = 0;
  for (i = 0; (c1 = s1[i]) != '\0'; ++i) {
    found = 0;
    for (j = 0; (c2 = s2[j]) != '\0'; ++j) {
      if (c1 == c2) {
        found = 1;
      }
    }
    if (found == 0) {
        s1[k++] = s1[i];
    }
  }
  s1[k] = '\0';
}