// exercise 1-24: write a program to check a C-program for rudimentary syntax errors like unbalanced parantheses, brackets and braces. Don't forget about single/dobule quotes, escape sequences and comments.
#include <stdio.h>

#define MAX_BUFFER 1000

void printError(char line[], int index, int lineNumber, char msg[]);
int mygetline(char line[], int limit);
int checkSyntax(char line[], int lineNumber);

int leadingParentheses = 0;
int leadingCurlyBrackets = 0;
int leadingSquareBrackets = 0;
int openSingleQuote = 0;
int openDoubleQuote = 0;
int commenting = 0;

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

void printError(char line[], int index, int lineNumber, char msg[]) {
    printf("%s", line);
    for (int i = 0; i < index; ++i) {
        printf(" ");
    }
    printf("^\n");
    printf("Error on line %d, %s\n", lineNumber, msg);
}

int mygetline(char line[], int limit) {
    int i,c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (i == 0) {
        return i;
    }
    line[i] = '\n';
    ++i;
    line[i] = '\0';
    return i;
}

int checkSyntax(char line[], int lineNumber) {
    int i,c;
    for (i = 0; (c = line[i]) != '\0'; ++i) {
        if (c == '/' && line[i + 1] == '*') {
            commenting = 1;
            ++i;
        }
        if (c == '*' && line[i + 1] == '/') {
            commenting = 0;
            ++i;
        }
        if (!commenting) {
            if (c == '/' && line[i + 1] == '/') {
                // comment, so ignore rest of line
                return 1;
            }
            if (c == '\\') {
                // escape character, so ignore what comes after
                ++i;
            }
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
                    printError(line, i, lineNumber, "unexpected )");
                    return 0;
                }
                --leadingParentheses;
            }
            if (c == '{') {
                ++leadingCurlyBrackets;
            }
            if (c == '}') {
                if (leadingCurlyBrackets == 0) {
                    printError(line, i, lineNumber, "unexpected }");
                    return 0;
                }
                --leadingCurlyBrackets;
            }
            if (c == '[') {
                ++leadingSquareBrackets;
            }
            if (c == ']') {
                if (leadingSquareBrackets == 0) {
                    printError(line, i, lineNumber, "unexpected ]");
                    return 0;
                }
                --leadingSquareBrackets;
            }
        }
    }

    return 1;
}