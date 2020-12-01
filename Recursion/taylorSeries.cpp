#include <iostream>

/*

e^x = SUM(1 + x + (x^2)/2! + (x^3)/3!...

*/

double calcSeries(int n, int x) {
	static double power = 1, factorial = 1;
	if (n == 0) {
		return 1;
	}
	double sum = calcSeries(n-1, x);
	power = power * x;
	factorial = factorial * n;
	return sum + power/factorial;
}


int main() {
	//e^x
	int x =4; 
	// the nth term the sequence
	int n = 15;
	std::printf("%lf \n", calcSeries(n, x));
}
