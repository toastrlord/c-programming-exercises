#include <stdio.h>

#define MAX_BUFFER 1000

int mygetline(char line[], int limit);
int checkSyntax(char line[], int lineNumber);

int leadingParentheses = 0;
int leadingCurlyBrackets = 0;
int leadingSquareBrackets = 0;
int openSingleQuote = 0;
int openDoubleQuote = 0;

main() {
    int lineNumber = 1;
    char line[MAX_BUFFER];
    while (mygetline(line, MAX_BUFFER) > 0) {
        checkSyntax(line, lineNumber);
        ++lineNumber;
    }
    if (leadingParentheses > 0) {
        printf("Expected )\n");
    }
    if (leadingCurlyBrackets > 0) {
        printf("Expected }\n");
    }
    if (leadingSquareBrackets > 0) {
        printf("Expected ]\n");
    }
    if (openSingleQuote > 0) {
        printf("Expected \'\n");
    }
    if (openDoubleQuote > 0) {
        printf("Expected \"\n");
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
    for (i = 0; (c = line[i]) != '\0'; ++i) {
        if (c == '\'') {
            openSingleQuote = !openSingleQuote;
        }
        if (c == '\"') {
            openDoubleQuote = !openDoubleQuote;
        }
        if (c == '(') {
            ++leadingParentheses;
        }
        if (c == ')') {
            if (leadingParentheses == 0) {
                printf("Error on line %d, unexpected )\n", lineNumber);
                return 0;
            }
            --leadingParentheses;
        }
        if (c == '{') {
            ++leadingCurlyBrackets;
        }
        if (c == '}') {
            if (leadingCurlyBrackets == 0) {
                printf("Error on line %d, unexpected }\n", lineNumber);
                return 0;
            }
            --leadingCurlyBrackets;
        }
        if (c == '[') {
            ++leadingSquareBrackets;
        }
        if (c == ']') {
            if (leadingSquareBrackets == 0) {
                printf("Error on line %d, unexpected ]\n", lineNumber);
                return 0;
            }
        }
    }
}