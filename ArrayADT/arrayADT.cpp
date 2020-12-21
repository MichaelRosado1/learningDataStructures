#include <iostream>

class Array {
	public:
		int *A;
		int length;
		int index;

		Array(int sizeOfArray) {
			this->A = new int[sizeOfArray];
			this->length = sizeOfArray;
			index = 0;
		}

		void push(int element) {
			if (index == this->length- 1) {
				std::cout<<"Array overflow\n";
			} else {
				A[index] = element;
				index++;
			}


		}

		void pop() {
			A[this->length- 1] = -1;
			index--;
		}

		void printAllElemets() {
			for (int i = 0; i <= (int)sizeof(this->A)/4; i++) {
				std::cout<<"element: "<<i<<" is equal to: "<<this->A[i]<<"\n";
			}
		}
};

int main() {
	Array *arr = new Array(10);
	arr->push(10);
	arr->push(30);
	arr->push(5);
	arr->printAllElemets();
}
