#include <stdio.h>

int main () {
    
    int a = 4, b = 5, c = 2;
    int result = a++ + --b * c - a / c;
    printf("%d%d%d \n", a,b,result);

    return 0;

}