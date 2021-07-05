#include <stdio.h>

#define MAX_BUFFER 1000

int mygetline(char line[], int limit);
int checkSyntax(char line[]);

main() {
    int lineNumber = 1;
    char line[MAX_BUFFER];
    while (mygetline(line, MAX_BUFFER) > 0) {
        checkSyntax(line);
        ++lineNumber;
    }
}

int mygetline(char line[], int limit) {
    int i,c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    line[i] = '\n';
    ++i;
    line[i] = '\0';
    return i;
}

int checkSyntax(char line[], int lineNumber) {
    int i,c;
    int leadingParentheses = 0;
    int leadingCurlyBrackets = 0;
    int leadingSquareBrackets = 0;
    for (i = 0; (c = line[i]) != '\0'; ++i) {
        if (c == '(') {
            ++leadingParentheses;
        }
        if (c == ')') {
            if (leadingParentheses == 0) {
                printf("Error on line %d, unexpected )", lineNumber);
                return 0;
            }
            --leadingParentheses;
        }
        if (c == '{') {
            ++leadingCurlyBrackets;
        }
        if (c == '}') {
            if (leadingCurlyBrackets == 0) {
                printf("Error on line %d, unexpected }", lineNumber);
                return 0;
            }
            --leadingCurlyBrackets;
        }
        if (c == '[') {
            ++leadingSquareBrackets;
        }
        if (c == ']') {
            if (leadingSquareBrackets == 0) {
                printf("Error on line %d, unexpected ]", lineNumber);
                return 0;
            }
        }
    }
}