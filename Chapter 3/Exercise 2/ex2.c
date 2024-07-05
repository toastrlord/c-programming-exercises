#include <stdio.h>
#define MAXLEN 1000
void escape(char* s, char* t);
void unescape(char *s, char *t);

int main() {
	char t[MAXLEN];
	char o[MAXLEN];
	escape("this	has	tabs \nand\nlinebreaks\n", t);
	printf("%s\n", t);
	unescape("test\\ntest \\ttabbed\\tend\\nnextline", o);
	printf("%s\n", o);

}

void escape(char* s, char* t) {
	while (*s) {
		switch (*s) {
		case '\n':
			*t = '\\';
			t++;
			*t = 'n';
			break;
		case '\t':
			*t = '\\';
			t++;
			*t = 't';
			break;
		default:
			*t = *s;
			break;
		}
		t++;
		s++;
	}
	*t = '\0';
}

void unescape(char* s, char *t) {
	while (*s) {
		if (*s == '\\') {
			char next = *(s+1);
			switch(next) {
				case 't':
					*t = '\t';
					s++;
					break;
				case 'n':
					*t = '\n';
					s++;
					break;
				default:
					*t = '\\';
					break;
			}

		}
		else {
			*t = *s;
		}
		t++;
		s++;
	}
	*t = '\0';
}
