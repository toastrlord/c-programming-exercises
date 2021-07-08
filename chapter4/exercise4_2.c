#include <stdio.h>
#include <math.h>
#include <ctype.h>

double atof(char s[]);

main() {
    printf("%f\n", atof("3.82e2"));
}

int substrAtoi(char s[], int start) {
    int i;
    for (i = start; isdigit(s[i]); i++);
    int digitEnd = i - 1;
    int result = 0;
    int pow = 1;
    for (i = digitEnd; i >= start; i--) {
        result += (s[i] - '0') * pow;
        pow *= 10;
    }

    return result;
}

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        int exponentSign = s[i] == '-' ? -1 : 1;
        if (s[i] == '-' || s[i] == '+') {
            i++;
        }
        int exponent = substrAtoi(s, i);
        val = val * pow(10.0, (double) exponentSign * exponent);
    }
    return val;
}