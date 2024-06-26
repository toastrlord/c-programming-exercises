#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main() {
    char s[] = "a\nfdfg \b\ta";
    char t[1000];
    escape(s, t);
    printf("Escaped: %s\n", t);
    unescape(s, t);
    printf("Unescaped: %s\n", t);
}

void escape(char s[], char t[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\a':
                t[j] = '\\';
                ++j;
                t[j] = 'a';
                break;
            case '\b':
                t[j] = '\\';
                ++j;
                t[j] = 'b';
                break;
            case '\e':
                t[j] = '\\';
                ++j;
                t[j] = 'e';
                break;
            case '\f':
                t[j] = '\\';
                ++j;
                t[j] = 'f';
                break;
            case '\n':
                t[j] = '\\';
                ++j;
                t[j] = 'n';
                break;
            case '\r':
                t[j] = '\\';
                ++j;
                t[j] = 'r';
                break;
            case '\t':
                t[j] = '\\';
                ++j;
                t[j] = 't';
                break;
            case '\v':
                t[j] = '\\';
                ++j;
                t[j] = 'v';
                break;
            default:
                t[j] = s[i];
        }
        ++j;
    }
    t[j] = '\0';
}

void unescape(char s[], char t[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '\\') {
            switch (s[i+1]) {
                case 'a':
                    t[j] = '\a';
                    break;
                case 'b':
                    t[j] = '\b';
                    break;
                case 'e':
                    t[j] = '\e';
                    break;
                case 'f':
                    t[j] = '\f';
                    break;
                case 'n':
                    t[j] = '\n';
                    break;
                case 'r':
                    t[j] = '\r';
                    break;
                case 't':
                    t[j] = '\t';
                    break;
                case 'v':
                    t[j] = '\v';
                    break;
            }
            ++i;
        }
        else {
            t[j] = s[i];
        }
        ++j;
    }
    t[j] = '\0';
}