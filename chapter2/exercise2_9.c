
/*  x &= (x - 1) deletes the rightmost 1 bit in x in a two's complement number system. 
    Explain why, and use this information to write a faster bitcount
    For instance, say x = 12, then x - 1 is 11 and 12 & 11 = 8. In Binary:
    12: 1100
    11: 1011
    &-------
    8:  1000    and once more gets us to zero
    7:  0111
    &-------
    0:  0000

    Generally, subtracting by 1 will replace the rightmost 1 of the original number with a zero, and since this was the RIGHTMOST 1 of the original number,
    you can see that performing a bitwise & will always remove the rightmost 1, without switching on any other bits.
    
    We can make a faster bitcount, since all we need to do is perform a single bitwise operation (x &= x-1), 
    then just check if x is 0. In the bitcount in the book, two bitwise operations are required: right-shifting x by 1, and
    checking if the rightmost digit is 1 using x & 01.
*/
int main() {

}

int bitcount(unsigned x) {
    int count = 0;
    for (x; x != 0; x &= x - 1) {
        ++count;
    }

    return count;
}