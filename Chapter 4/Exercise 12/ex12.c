#include <stdio.h>

double itoa(char []);

int main() {
}

double itoa(char s[]) {
	int i = 0;
	char c;
	while ((c = s[i]) != ' ' && s[i] != '\t') {
		i++;
	}
	if (isdigit(s[i])) {
		double num = s[i] - '0';
		return num + 10 * itoa(s + i);
	}
	return 0.0;
}
