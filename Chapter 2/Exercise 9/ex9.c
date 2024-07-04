#include <stdio.h>

int bitcount(unsigned x);
void bitcount_wrapper(unsigned x);


int main() {
	for (int i = 0; i <= 30; i++) {
		bitcount_wrapper(i);
	}

}

int bitcount(unsigned x) {
	int b = 0;
	while (x != 0) {
		x &= x - 1;
		b++;
	}
	return b;
}

void bitcount_wrapper(unsigned x) {
	printf("Bitcount for %d: %d\n", x, bitcount(x));
}
