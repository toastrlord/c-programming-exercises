#include <stdio.h>

int any(char s1[], char s2[]);

main() {
  char str1[] = "I love llamas";
  char str2[] = "afG ";
  printf("%d\n", any(str1, str2));
}

int any(char s1[], char s2[]) {
  int c1, c2;
  for (int i = 0; (c1 = s1[i]) != '\0'; ++i) {
    for (int j = 0; (c2 = s2[j]) != '\0'; ++j) {
      if (c1 == c2) {
        return i;
      }
    }
  }
  return -1;
}