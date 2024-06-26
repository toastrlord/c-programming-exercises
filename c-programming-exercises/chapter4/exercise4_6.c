

/*
    start exercise 4-6 functions
    4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 4-6 
*/
double variables[26 * 2]; // array for storing variable values

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