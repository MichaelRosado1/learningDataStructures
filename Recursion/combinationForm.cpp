#include <iostream>

/*
   formula to calculate the amount of combinations, C, can be done with a set of size
   n and number of choosing objects r 

								C = (n!)/r!(n-r)! 


	Pascals triangle can show us the combinations with a set n and objects r

*/

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return factorial(n-1) * n;
}

int ncr(int n, int r) {
	//pascals triangle follows this form
	if (n == r || r == 0) {
		return 1;
	} else {
		return ncr(n-1, r-1) + ncr(n-1,r);
	}	
}

int main() {
	printf("%d \n", ncr(4,2));
}
