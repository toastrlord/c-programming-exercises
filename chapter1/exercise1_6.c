// exercise 1-6: verify that the expression getchar() != EOF is 0 or 1
#include <stdio.h>

main() {
    char c;
    // verify that expression getchar() != EOF is 0 or 1
    // boolean expression, so should always evaluate to 0 or 1
    while ((c = getchar()) != EOF) {
        printf("%d", c != EOF);
    }
    printf("%d", c!= EOF);
}