#include <stdio.h>

// predict the output of the given program

int main () {
    int a = 5, b=2;
    float result;

    result = a/b;
    printf("%.2f\n", result);

    return 0;
}

// the answer will be 2.00 because the division is in integer but the result is converted to the float value which still will be 2.0