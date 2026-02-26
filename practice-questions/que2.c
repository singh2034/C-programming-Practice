#include <stdio.h>

// What is wrong here, identify it and correct it.

int main () {
    int a = 5;
    // int b = a + c; // wrong line as you cannot perform a operation on something that is not yet declared.
    int c = 10;
    int b = c + a;

    // now it is correct and we can print the operation

    return 0;
}