#include <stdio.h>

char lower(char in);

int main() {
	for (int i = 'A'; i <= 'z'; ++i) {
		printf("%c => %c\n", i, lower(i));
	}
}

char lower(char in) {
	return in >= 'A' && in <= 'Z' ? in - ('A' - 'a') : in;
}


