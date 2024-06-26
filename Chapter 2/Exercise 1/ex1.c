#include <stdio.h>

main() {
  // reporting the header values is lame, will determine programattically
  signed int mySInt = 0;
  signed short mySShort = 0;
  signed long mySLong = 0;
  signed char mySChar = 0;
  
  signed int prevValue = mySInt;
  signed char sInt;
  while(1) {
    signed char i = mySChar;
    mySChar++;
    if (i > mySChar) {
      printf("Signed Char Max: %d\n", i);
      break;
    }
  }
  mySChar = 0;
  while(1) {
    signed char i = mySChar;
    mySChar--;
    if (i < mySChar) {
      printf("Signed Char Min: %d\n", i);
      break;
    }
  }
  while(1) {
    signed short i = mySInt;
    mySInt++;
    if (i > mySInt) {
      printf("Signed Int Max: %d\n", i);
      break;
    }
  }
  mySInt = 0;
  while(1) {
    signed short i = mySInt;
    mySInt--;
    if (i > mySInt) {
      printf("Signed Int Min: %hi\n", mySInt);
      break;
    }
  }
}