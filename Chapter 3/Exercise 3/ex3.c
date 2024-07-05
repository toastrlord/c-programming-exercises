#include <stdio.h>
#define MAXLEN 1000

void expand(char* s1, char* s2);
int isletter(char c);
int isnumber(char c);
int isnotation(char c);

int main() {
	char  s2[MAXLEN];
	expand("a-z", s2);
	printf("%s\n", s2);
}

// arrange so that a leading or trailing dash is taken literally? as in a negative sign? or as in the actual dash character?
void expand(char* s1, char* s2) {
	int start, end;
	while (*s1) {
		if (isnotation(*s1)) {
			if (*(s1+1) == '-' && isnotation(*(s1+2))) {
				start = *s1;
				end = *(s1 + 2);
				for (int i = start; i <= end; i++) {
					*s2 = i;
					s2++;
				}
				s1 +=  3;
			}
		}
		else if (*s1 == '-') {
			if (isnotation(*(s1+1))) {
				start = end; //assumes we had a valid ending point already
				end = *(s1+1); 
				for (int i = start; i <= end; i++) {
					*s2 = i;
					s2++;
				}
				s1 += 2;
			}
			s1++;
		} else {
			s1++;
		}
	}
	*s2 = '\0';
}

int isletter(char c) {
	return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

int isnumber(char c) {
	return c >= '0' && c <= '9';
}

int isnotation(char c) {
	return isletter(c) || isnumber(c);
}
