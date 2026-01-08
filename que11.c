// write a program to print - sum of two integers, sum of one integer and one float, sum of two floats.
#include <stdio.h>


int main () {
    int a,b; float c,d;
    int result, result_2;
    // sum of 2 integers
    a = 2; b = 3;
    result = a+b;
    printf("%d\n",  result);

    // sum of 1  float & 1 integer
    c = 2.2; d = 4.2;
    result_2 = c+d;
    printf("%d\n", result_2);

    
    return 0;

}