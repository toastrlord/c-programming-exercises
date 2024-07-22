#include <stdio.h>
#include <ctype.h>
double atof(char s[]);

void wrapper(char s[]);
int main() {
	wrapper("12.56e0");
	wrapper("5e2");
	wrapper("-5e+2");
	wrapper("1e-3");
	wrapper("1.2345");
}

void wrapper(char s[]) {
	printf("%s => atof => %e\n", s, atof(s));
}

double atof(char s[]) {
	double val, power, e;
	int i, sign;
	e = 1.0;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+') {
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
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		int esign = s[i] == '-' ? -1 : 1;
		if (s[i] == '-' || s[i] == '+') { 
			i++;
		}
		int digitstart;
		digitstart = i;
		double pow;
		double powermag = 0.0;
		for (pow = 1.0; isdigit(s[i+1]); i++) { 
			pow *= 10.0;
		}
		for (i = digitstart; isdigit(s[i]); i++) {
			powermag = pow * (s[i] - '0');
			pow /= 10.0;
		}
		if (powermag == 0) {
			e = 1.0;
		}
		for (int j = 1; j <= powermag; j++) { // can be faster! calculate e*e if exponent is even, and divide exponent by 2. otherwise e*=10, exponent-- 
			e *= 10;
		}
		if (esign < 0) {
			e = 1.0 / e;
		}
	}
	return sign * val / power * e;
}
