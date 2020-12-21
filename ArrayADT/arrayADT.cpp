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

		void shiftNumsOver(int position) {
			if (position > this->length - 1) {
				std::cout<<"Not a valid position";
			} else {
				for (int i = position + 1; i < this->length; i++) {
					int temp = this->A[i];
					this->A[i] = -1;
					this->A[i+1] = temp;
				}
			}
		}
		void copyArrayandIncreaseSize() {
			int *copy = new int[this->length + 1];
			for (int i = 0; i < this->length - 1; i++) {
				copy[i] = this->A[i];
			}	
			this->A = copy;
		}
		void insert(int position, int element) {
			this->copyArrayandIncreaseSize();
			this->shiftNumsOver(position);	
			this->A[position] = element;

		}
};

int main() {
	Array *arr = new Array(10);
	arr->push(10);
	arr->push(30);
	arr->push(5);
	arr->insert(2, 1000);
	arr->printAllElemets();
}
