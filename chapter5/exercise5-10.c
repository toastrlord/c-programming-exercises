#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK 100
#define MAX_STRING_SIZE 100
static float stack[MAX_STACK];
int stackIndex = 0;
char currentArg[MAX_STRING_SIZE];

void doOperation(char);
int isOperator(char);
void push(float);
float pop();

// NOTE: need to escape multiplication symbol!

main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: exercise5-10 numbers operators\n");
    }
    int i = 0;
    while (++i < argc) {
        strcpy(currentArg, *++argv);
        if (strlen(currentArg) == 1 && isOperator(currentArg[0])) {
            doOperation(currentArg[0]);
        }
        else {
            push(atof(currentArg));
        }
    }
    printf("%f\n", pop());
}

void doOperation(char op) {
    float arg1, arg2, result;
    arg1 = pop();
    arg2 = pop();
    switch(op) {
        case '+':
            result = arg1 + arg2;
            break;
        case '-':
            result = arg1 - arg2;
            break;
        case '*':
            result = arg1 * arg2;
            break;
        case '/':
            result = arg1 / arg2;
            break;
        default:
            printf("Invalid operator: %c\n", op);
            push(arg2);
            push(arg1);
            return;
    }
    push(result);
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

void push(float number) {
    if (stackIndex == MAX_STACK) {
        printf("Error: tried to push a value to a full stack\n");
        return;
    }
    stack[stackIndex++] = number;
}

float pop() {
    if (stackIndex == 0) {
        printf("Error: tried to pop a value from an empty stack!");
    }
    return stack[--stackIndex];
}