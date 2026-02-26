#include <stdio.h>

int main () {
    
    int a = 4, b = 5, c = 2;
    int result = a++ + --b * c - a / c;
    printf("%d%d%d \n", a,b,result);

    return 0;

}

// a++ = post increment
//--b = pre decrement
// a++ + --b * c - a / c = 4 + 4 * 2 - 5 / 2 = 4 (first use expression) + 8 - 2 ( Integer value not float ) = 10
// triple d used without space so the answer is = 5410 ( a,b,result)
