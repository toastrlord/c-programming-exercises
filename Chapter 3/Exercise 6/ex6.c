#include <stdio.h>
#define MAXLEN 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
	char s[MAXLEN];
	itoa(-512, s, 6);
	printf("%s\n", s);
}

void itoa(int n, char s[], int w) {
	int i, sign;
	if ((sign = n) < 0)
			n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0) 
		s[i++] = '-';
	while (i < w) {
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int i = 0;
	while (*(s+i)) {
		i++;
	}
	i--;
	for (int j = 0; j < i; j++) {
		char tmp;
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i--;
	}
}
