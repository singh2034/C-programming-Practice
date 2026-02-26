#include <stdio.h>

// explain a=b+c valid & b+c=a is invalid

int main () {
    int a,b,c;

    a = b+c; // valid because only left side of expression is modifiable not r side.
    // b+c = a; // invalid because we can only store  a calculation into a variable but on the left side, like if 1 box can store 5 small boxed but 5 small boxed cannot hold the 1 box inside them.

    return 0;

}