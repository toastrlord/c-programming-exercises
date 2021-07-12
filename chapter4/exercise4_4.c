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