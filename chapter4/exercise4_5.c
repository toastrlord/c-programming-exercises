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