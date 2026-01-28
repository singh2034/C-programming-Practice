#include <stdio.h>


// defines a function and takes an integer c - representing a character as input.
int transform(int c) {
	// using bitwise NOT Operator ~ for flipping the binary 0 to 1 and 1 to 0.
	// for example :- for A -> in 8 bit binary is -> 01000001 and ~ using this -> 10111110 (flipped)
	return ~c;
}


int main () {
	// var declare so that, it stores a character being processed, for handling the EOF (End of file) signal.
	// I have used int rather than char, so that it can handle the EOF signal very well.
	int c;
	// getchar() reads a single keyboard characters, and stores in the int c.
	while ((c = getchar()) != EOF)
		// putchar() is printing the transformed c character on the screen.
		putchar(transform(c));
}
