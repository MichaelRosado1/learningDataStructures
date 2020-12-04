#include <iostream>

int findNthTerm(int n) {
	// first 2 terms are 1
	if (n < 2) {
		return 1;
	}
	//we want to add the previous and second to previous terms in the sequence in order to get
	//the next term
	return findNthTerm(n - 1) + findNthTerm(n - 2);
}
int main() {
	int n = 10;
	std::cout<<findNthTerm(n);
}
