#include <stdio.h>
#include <limits.h>
#define INT_BITS sizeof(int)
#define MAX_INT 1 << sizeof(int) * 4

int rightRot(int x, int n);

int main() {
	printf("Left shift test\n");
	for (int i = 0; i <= 16; i++) {
		printf("leftshift i=%d, %d\n", i, 3 << i);
	}
	for (int i = 0; i <= 16; i++) {
		printf("rightRot i=%d, %d\n", i, rightRot(3,i));
	}

}

int rightRot(int x, int n) {
/* procedure:
 * take the rightmost bit, if 0, just right shift by 1 and skip the rest of the operation
 * if 1, then leftshift by sizeof(int) * 4, x |= mask
 * repeat until i == n
 */
	int finalMask = 0;
	for (int i = 0; i < n; i++) {
		int rightMost = 1 & x;
		x = x >> 1;
		if (rightMost > 0) {
			x |= MAX_INT;
		}
	}
	return x;
}
