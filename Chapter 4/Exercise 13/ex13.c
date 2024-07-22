#include <stdio.h>

void reverse(char[]);
void reverseinner(char[], int, int);

int main() {
	char s1[] = "012345678";
	reverse(s1);
	printf("%s\n", s1);
	char s2[] = "";
	reverse(s2);
	printf("%s\n", s2);
	char s3[] = "0";
	reverse(s3);
	printf("%s\n", s3);
	char s4[] = "01";
	reverse(s4);
	printf("%s\n", s4);
}

void reverse(char s[]) {
	int i = 0;
	char c;
	while ((c = *(s+i)) != '\0') {
		i++;
	}
	reverseinner(s, 0, i-1);
}

void reverseinner(char s[], int start, int end) {
	if (start >= end) {
		return;
	}
	char tmp = *(s + start);
	*(s + start) = *(s + end);
	*(s + end) = tmp;
	reverseinner(s, start + 1, end - 1);
}
