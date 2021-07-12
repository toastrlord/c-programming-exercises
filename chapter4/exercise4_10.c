#include <stdio.h>

#define MAXOP 100 // maximum size of operand/operator
#define MAXVAL 100 // maximum depth of val stack
#define NUMBER '0' // signal that a number was found
#define MAX_LINE 1000
char line[MAX_LINE];
int lineIndex = 0;

main() {
    int type;
    double op2;
    char line[MAX_LINE];
    getline(line, MAX_LINE, stdin);
    // get the line
    // split by whitespace
    // feed one 'word' to getop at a time for processing
    char s[MAXOP];
    readNext(line, s);
    
    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: divide by zero\n");
                }
                break;
            case '%': // exercise 4-3: add modulus operator
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                if (type >= 'a' && type <= 'z' || type >= 'A' && type <= 'Z') {
                    push(fetchVar(type));
                }
                printf("error: unknown command %s\n", s);
                break;
        }
        readNext(line, s);
    }
    return 0;
}

void readNext(char line[], char op[]) {
    int j = 0;
    int c;
    while ((c = line[lineIndex]) == ' ' || c == '\t') {
        lineIndex++;
    }
    for (lineIndex; (c = line[lineIndex]) != EOF && c != ' ' && c != '\0'; lineIndex++) {
        op[j] = c;
        j++;
    }
    op[j] = '\0';
}

// getop: get next operator or numeric operand
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    if (isdigit(c)) { // collect integer portion
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') { // collect fractional portion
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}