// write a program to show the working of the modulus - Positive & Negative numbers.

#include <stdio.h>


// in this case whatever the sign with dividend is, the answer will be the sign follows the dividend

int main () {
    int a,b;
    int value_a, value_b, value_c, value_d;
    a=10, b=3;

    // positive dividend, positive divisor = positive quotient
    value_a = a % b;
    // negative dividend, positive divisor = negative quotient
    value_b = -a % b;
    // positive dividend, negative divisor = positive quotient
    value_c = a % -b;
    // negative dividend, negative divisor = negative quotient
    value_d = -a % -b;

    printf("value_a = %d\nvalue_b = %d\nvalue_c = %d\nvalue_d = %d\n", value_a, value_b, value_c, value_d);

    return 0;
}