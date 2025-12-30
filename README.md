# C-programming-Practice

Q1️⃣ (Type Declaration + Concept)
Write a C program to:
Declare three integer variables a, b, and c
Assign the value 50 to all three using a single statement
Increase b by 10 and c by 20
Print all three values
👉 Hint: a = b = c = value;

Q2️⃣ (Declaration Validity – Tricky)
Identify whether the following declaration is valid or invalid.
If invalid, correct it and explain why.
C
int a = 5;
int b = a + c;
int c = 10;

Q3️⃣ (Arithmetic + Integer Division)
Predict the output of the following code:
C
#include <stdio.h>
int main() {
    int x = 7, y = 2;
    printf("%d\n", x / y);
    printf("%d\n", x % y);
    printf("%d\n", x + y * x);
    return 0;
}

Q4️⃣ (Operator Precedence – Hard)
Predict the output:
C
#include <stdio.h>
int main() {
    int a = 4, b = 5, c = 2;
    int result = a++ + --b * c - a / c;
    printf("%d %d %d\n", a, b, result);
    return 0;
}

Q5️⃣ (Type Conversion – Thinking Based)
Predict the output and justify your answer:
C
#include <stdio.h>
int main() {
    int a = 5, b = 2;
    float result;
    result = a / b;
    printf("%.2f\n", result);
    return 0;
}
