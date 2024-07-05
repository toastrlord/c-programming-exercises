#include <stdio.h>
#define MAXLEN 1000

void itoa(int n, char s[]);
void reverse(char s[]);
int abs(int n);

int main() {
	int n;
	char s[MAXLEN];
	itoa(-2147483648, s);
	printf("%s\n", s);
}

// ex: -6 in two's complement
// 0110 in decimal
// 1001 invert all bits
// 1010 after adding one


void itoa(int n, char s[]) {
	int i, sign;
	i = 0;
	sign = n;
	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0) {
		s[i++] = '-';
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
		char tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i--;
	}
}

int abs(int n) {
	if (n <0) {
		return n;
	} else {
		return -n;
	}
}
