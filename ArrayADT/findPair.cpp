#include <iostream>

struct Array {
	int a[10];
	int size;
	int length;

};

bool findPair(struct Array arr, int sumToCheck) {
	for (int i = 0; i < arr.size; i++) {
		for (int j = i + 1; j < arr.size; j++) {
			if (arr.a[i] + arr.a[j] == sumToCheck) {
				return true;
			} else {
				continue;
			}
		}
	}		
	return false;
}


int main() {
	struct Array arr = {{1,20,34,48,54,68,72,84,99,104}, 10, 9};

	int sumToCheck = 49;

	std::cout<<"is there a pair in the array that adds to: "<<sumToCheck<<"? : "<<findPair(arr, sumToCheck)<<std::endl;
}
