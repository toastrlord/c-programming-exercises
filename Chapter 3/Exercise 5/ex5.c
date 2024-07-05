#include <stdio.h>
#define MAXLEN 1000

void itob(int n, char* s, int b);
void reverse(char* s);

int main() {
	char s[MAXLEN];
	for (int i = 0; i <= 32; i++) {
		itob(i, s, 16);	
		printf("%d = %s\n", i, s);
	}
}

void itob(int n, char* s, int b) {
	if (b < 2 || b > 36) {
		printf("itob: b must be between 2 and 36\n");
		return;
	}
	int i = 0;
	do {
		int rem = n % b;
		if (rem < 10) {
			s[i++] = rem + '0';
		} else {
			s[i++] = rem - 10 + 'a';
		}
	} while ((n /= b) > 0);
	s[i] = '\0';
	reverse(s);
}

void reverse(char* s) {
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
