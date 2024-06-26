#include <stdio.h>
#include <float.h>
#include <limits.h>

main() {
    printf("Min char: %d\n", CHAR_MIN);
    printf("Max char: %d\n", CHAR_MAX);
    printf("Min short: %d\n", SHRT_MIN);
    printf("Max short: %d\n", SHRT_MAX);
    printf("Min int: %d\n", INT_MIN);
    printf("Max int: %d\n", INT_MAX);
    printf("Max long: %ld\n", LONG_MAX);
    printf("Min long: %ld\n", LONG_MIN);
}