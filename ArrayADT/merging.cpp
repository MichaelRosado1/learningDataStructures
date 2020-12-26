#include <iostream>
#include <iterator>

class Array {
	int length;
	int index;
	int *A;
	public:
		Array() {
			this->length = 10;
			this->index = 0;
			this->A = new int[this->length];
		}

		int getSize() {
			return this->index;
		}
		int* makeABiggerCopy() {
			int newLength = this->length * 2;
			int originalLength = this->length;

			int* toReturn = new int[newLength];

			for (int i = 0; i < originalLength; i++) {
				toReturn[i] = this->A[i];
			}

			return toReturn;
		}

		int at(int index) {
			return this->A[index];
		}

		void print() {
			for (int i = 0; i < this->index; i++) {
				std::cout<<"Element: "<<i<<" is equal to: "<<this->A[i]<<"\n";
			}
		}

		void push(int element) {
			if (this->index == this->length) {
				std::cout<<"Array has been resized\n";
				this->A = makeABiggerCopy();
				this->A[index] = element;
				this->index++;
			} else {
				this->A[this->index] = element;
				this->index++;
			}
		}
};

int* mergeArrays(Array *arr1, Array *arr2) {
	int i = 0;
	int j = 0;
	int k = 0;
	int* toReturn = new int[arr1->getSize() + arr2->getSize()];

	while (i < arr1->getSize() && j < arr2->getSize()) {
		if (arr1->at(i) < arr2->at(j)) {
			k++;
			i++;
			toReturn[k]= arr1->at(k);	
		} else {
			k++;
			j++;
			toReturn[k] = arr2->at(j);	
		}

	}
	while (i < arr1->getSize()) {
		k++;
		i++;
		toReturn[k] = arr1->at(i);
	}

	while (j < arr2->getSize()) {
		k++;
		j++;
		toReturn[k] = arr2->at(j);
	}
	return toReturn;
}

Array *myArray;
Array *arr2;

void printElements(int* array) { 
	for (int i = 0; i < myArray->getSize() + arr2->getSize(); i++) {
		std::cout<<"Element: "<<i<<" is equal to: "<<array[i]<<"\n";
	}	
}
int main() {

	myArray = new Array();
	myArray->push(1);
	myArray->push(3);
	myArray->push(5);
	myArray->push(7);
	myArray->push(9);

	arr2 = new Array();
	arr2->push(2);
	arr2->push(4);
	arr2->push(6);
	arr2->push(8);
	arr2->push(10);


	int* merged = mergeArrays(myArray, arr2);

	printElements(merged);
	

}
