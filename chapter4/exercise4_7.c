// exercise 4-7 function
void ungets(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        ungetch(s[i]);
    }
}