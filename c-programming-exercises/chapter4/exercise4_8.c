// exercise 4_8: modify getch and ungetch, presuming that there is only ever 1 character of pushpack
int hasCharacter = 0;
char lastChar;

int getch(void) {
    if (hasCharacter) {
        hasCharacter = 0;
        return lastChar;
    }
    return getchar();
}

void ungetch(char c) {
    hasCharacter = 1;
    lastChar = c;
}