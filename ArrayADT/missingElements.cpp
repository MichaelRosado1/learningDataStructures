#include <iostream> 

int findMissingElementInSortedArray(int array[], int size) {
	//sum of n many natural numbers is equal to ((n * (n+1))/2)
	int sumOfArrUsingForm = ((size) * (size + 1)) / 2;

	int sum = 0; 

	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	std::cout<<"Sum of array: "<<sum<<std::endl;

	//if there is an element missing, the sum found will be greater than the 
	//formula sum
	return sumOfArrUsingForm - sum;
}

int main() {
	int array[] = {1,2,3,4,5,6,8,9,10,11,12};
	std::cout<<"size of array: "<<sizeof(array)<<std::endl;
	std::cout<<"size of array[0]: "<<sizeof(array[0])<<std::endl;
	int nTerms = (sizeof(array) / sizeof(array[0])) + 1;
	std::cout<<"Missing element is: "<<findMissingElementInSortedArray(array, nTerms);

}
