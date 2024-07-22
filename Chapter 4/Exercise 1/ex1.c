#include <stdio.h>
#define MAXLEN 1000

int strrindex(char s[], char t[]);
void wrapper(char s[], char t[]);

int main() {
	wrapper("123456789", "");
	wrapper("123456789", "0");
	wrapper("123456789", "12");
	wrapper("12345678912", "12");
}

int strrindex(char s[], char t[]) {
	int i, j, k;
	k = -1;
	if (t[0] == '\0') {
		return -1;
	}
	for (i = 0; s[i] != '\0'; i++) {
		//printf("i=%d\n", i);
		for (j = 0; s[j+i] == t[j] || t[j] == '\0'; j++) {
			if (t[j] == '\0') {
				k = i;
			}
			if (s[j] == '\0') {
				break;
			}
		}
	}
	return k;
}

void wrapper(char s[], char t[]) {
	printf("last index of %s in %s: %d\n", t, s, strrindex(s,t));
}
