#include <stdio.h>

// write a program that shows invalid declaration order, then correct it in the same using comments

int main () {

    int a=23;
    // b=c;

    printf("%d\n", a);

    return 0;
}