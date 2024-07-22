#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define VARIABLE 'a'
#define BUFSIZE 100
#define MAXVAL 1000
#define MAXVARS 26+1

double vars[MAXVARS];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(char);
int isvariable(char);
double getvar(char);
void setvar(char, double);
void ungets(char []);

int main() {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case 'a' ... 'z':
			push(getvar(type));
			break;
		case 'P':
			push(getvar('P'));
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
				printf("error: zero division\n");
			}
			break;
		case '%':
			op2 = pop();
			push(pop() / op2);
			break;
		case '!': // print top of stack
			op2 = pop();
			printf("\t%.8g\n",op2);
			push(op2);
			setvar('P', op2);
			break;
		case '@': // swap the two elements
			op2 = pop();
			double op1 = pop();
			push(op2);
			push(op1);
			break;
		case '#': //duplicate the top element
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case '^':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case '~':
			push(exp(pop()));
			break;
		case '=': //variable assignment
			char var = getch();
			op2 = pop();
			setvar(var, op2);
			push(op2);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;

		}
	}
	return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f) {
	val[sp] = f;
	sp++;
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[]) {
	int i, c;
	int sign = 1;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (c == '-') {
		if (!isdigit(c = getch())) {
			ungetch(c);
			return '-';
		} else {
			ungetch(c);
			sign = -1;
		}
	} else if (!isdigit(c) && c != '.') {
		return c;
	}
	i = 0;
	if (isdigit(c)) {
		while(isdigit(s[++i] = c = getch()))
			;
		if (c == '.') {
			while (isdigit(s[++i] = c = getch()))
					;
		}
		s[i] = '\0';
		if (c != EOF) {
			ungetch(c);
		}
	}
	return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}

}

double getvar(char c) {
	if (c == 'P') {
		return vars[MAXVARS - 1];
	}
	if (isvariable(c)) {
		return vars[c - 'a'];
	} else {
		printf("getvar: illegal variable name %c\n", c);
		return 0.0;
	}
}

void setvar(char c, double d) {
	if (c == 'P') {
		vars[MAXVARS - 1] = d;
		return;
	}
	if (isvariable(c)) {
		vars[c - 'a'] = d;
	} else {
		printf("setvar: illegal variable name %c\n", c);
	}
}

int isvariable(char c) {
	if (c == 'P') {
		return 1;
	} else {
		return c >= 'a' && c <= 'z';
	}
}

void ungets(char s[]) {
	for (int i = 0; s[i] && s[i] != EOF; i++) {
		ungetch(s[i]);
	}
}
