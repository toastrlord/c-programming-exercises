#include <stdio.h>

void printHistogram(int *results, int max, int minChar, int maxChar);

main() {
  int c, lowercaseMax, uppercaseMax, numbersMax;
  int lowercase[26], uppercase[26], numbers[10];
  lowercaseMax = uppercaseMax = numbersMax = 0;
  for (int i = 0; i < 26; i++) {
    lowercase[i] = 0;
    uppercase[i] = 0;
  }
  for (int i = 0; i < 10; i++) {
    numbers[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      lowercase[c - 'a']++;
      if (lowercase[c - 'a'] > lowercaseMax) {
        lowercaseMax = lowercase[c - 'a'];
      }
    }
    if (c >= 'A' && c <= 'Z') {
      uppercase[c - 'A']++;
      if (uppercase[c - 'A'] > uppercaseMax) {
        uppercaseMax = uppercase[c - 'A'];
      }
    }
    if (c >= '0' && c <= '9') {
      numbers[c - '0']++;
      if (numbers[c - '0'] > numbersMax) {
        numbersMax = numbers[c - '0'];
      }
    }
  }
  printHistogram(lowercase, lowercaseMax, 'a', 'z');
  printHistogram(uppercase, uppercaseMax, 'A', 'Z');
  printHistogram(numbers, numbersMax, '0', '9');
}

void printHistogram(int *results, int max, int minChar, int maxChar) {
  for (int i = max; i > 0; i--) {
    for (int j = 0; j <= (maxChar - minChar); j++) {
      if (results[j] >= i) {
        printf(" *");
      }
      else if (results[j] > 0) {
        printf("  ");
      }
    }
    putchar('\n');
  }
  for (int i = 0; i <= (maxChar - minChar); i++) {
    if (results[i] > 0) {
      putchar(' ');
      putchar(minChar + i);
    }
  }
  putchar('\n');
}