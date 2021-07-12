#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 // maximum size of operand/operator
#define MAXVAL 100 // maximum depth of val stack
#define NUMBER '0' // signal that a number was found
#define STR_OP '1' // signal that a library function was found (exercise 4-5)

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack
double variables[26 * 2]; // array for storing variable values

int getop(char []);
void push(double);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void printStack(void);
int getch(void);
void ungetch(char);
int mystrequal(char [], char []);
double fetchVar(char);
void storeVar(char, double);
void ungets(char []);

/*  reverse Polish notation calculator
    ex: 2 3 + = 5
        (1 2 +) (2 3 +) - = -2
*/

main() {
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch(type){
            /* exercise 4-5: add access to library functions */
            case STR_OP: // for operations of multiple characters
                if (mystrequal(s, "sin")) {
                    push(sin(pop()));
                }
                else if (mystrequal(s, "cos")) {
                    push(cos(pop()));
                }
                else if (mystrequal(s, "exp")) {
                    push(exp(pop()));
                }
                else if (mystrequal(s, "assign")) {
                    op2 = pop();
                    storeVar()
                }
                else {
                    printf("error: unknown library function %s\n", s);
                }
                break;
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
            case '^': // exercise 4-5: add access to library functions
                op2 = pop();
                push(pow(pop(), op2));
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
    }
    return 0;
}

// getop: get next operator or numeric operand
int getop(char s[]) {
    int i, c, sign;
    i = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        while(c != ' ' && c != '\n' && c != EOF) {
            s[i++] = c;
            c = getch();
        }
        s[i] = '\0';
        if (i > 1) {
            ungetch(c);
            return STR_OP;
        }
        return c;
    }
    if (c == '-') { // exercise 4-3: handle negative numbers
        if (!isdigit(c = getch())) {
            ungetch(c);
            return '-';
        }
        ungetch(c);
    }
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

// push: push f onto the value stack
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// pop: return the value on top of the stack
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) {
    if (bufp < BUFSIZE) {
        buf[bufp++] = c;
    }
    else {
        printf("error: character buffer full\n");
    }
}
