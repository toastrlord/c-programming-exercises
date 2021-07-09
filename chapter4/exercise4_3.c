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

/* 
    begin exercise 4-4 functions
    4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 
*/

// peek: look at the top value without popping it
void peek(void) {
    printf("\t%.8g\n", val[0]);
}

// duplicate: duplicate the top value of the stack
void duplicate(void) {
    double temp1, temp2;
    temp1 = val[0];
    sp++;
    for (int i = 0; i < sp; i++) {
       temp2 = val[i + 1];
       val[i + 1] = temp1;
       temp1 = temp2;
    }
    for (int i = 0; i < sp; i++) {
        printf("%g ", val[i]);
    }
    printf("\n");
}

// swap: swap the top value and the next value of the stack
void swap(void) {
    if (sp >= 2) {
        double temp = val[0];
        val[0] = val[1];
        val[1] = temp;
    }
    else {
        printf("error: cannot swap; only %d elements in stack\n", sp);
    }
}

void printStack(void) {
    for (int i = 0; i < sp; i++) {
        printf("%g ", val[i]);
    }
    printf("\n");
}

// clear: clear the stack
void clear(void) {
    sp = 0;
}

/* 
    4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 4-4 
    end exercise 4-4 functions
*/

/*
    begin exercise 4-5 functions
    4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 
*/
int mystrequal(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    if (s1[i] == s2[i]) { // check if lengths are the same (s1[i] and s2[i] should both be a null terminator)
        return 1;
    }
    return 0;
}
/*
    4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5
    end exercise 4-5 functions
*/

/*
    start exercise 4-6 functions
    4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 
*/
double fetchVar(char c) {
    if (c >= 'a' && c <= 'z') {
        return variables[c - 'a'];
    }
    if (c >= 'A' && c <= 'Z') {
        return variables[26 + c - 'A'];
    }
    printf("error: tried to fetch a var that is not alphabetic: %c\n", c);
}

void storeVar(char c, double val) {
    if (c >= 'a' && c <= 'z') {
        variables[c - 'a'] = val;
    }
    if (c >= 'A' && c <= 'Z') {
        variables[26 + c - 'A'] = val;
    }
    printf("error: tried to assign to a var that is not alphabetic: %c\n", c);
}
/*
    4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 
    end exercise 4-6 functions
*/

// exercise 4-7 function
void ungets(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        ungetch(s[i]);
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
