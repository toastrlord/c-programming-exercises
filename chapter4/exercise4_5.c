/*
    begin exercise 4-5 functions
    4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 
*/
int mystrequal(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    if (s1[i] == s2[i]) { // check if lengths are the same (s1[i] and s2[i] should both be a null terminator)
        return 1;
    }
    return 0;
}
/*
    4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5 4-5
    end exercise 4-5 functions
*/