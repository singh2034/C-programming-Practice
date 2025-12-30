#include <stdio.h>

int main () {

    int x=7, y=2;

    printf("%d \n", x / y); // 3 as the answer is not in float
    printf("%d \n", x % y); // 1 (7-6=1)
    printf("%d \n", x + y * x); // 21 (BODMAS)
    
    return 0;
}