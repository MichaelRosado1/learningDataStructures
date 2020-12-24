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
			for (int i = 0; i <= this->index - 1; i++) {
				std::cout<<"element: "<<i<<" is equal to: "<<this->A[i]<<"\n";
			}
		}

		void shiftNumsOver(int position) {
			int *copy = new int[this->length + 1];
			if (position > this->length - 1) {
				std::cout<<"Not a valid position";
			} else {
				for (int i = 0; i < this->index - 1; i++) {
					std::cout<<this->A[i]<<"\n";
					if (i == position) {
						copy[i] = -1;
						copy[i + 1] = this->A[i];
						continue;
					}
					if (i > position) {
						copy[i + 1] = this->A[i];
						continue;
					}
					copy[i] = this->A[i];
				}
				this->A = copy;
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

		//deletes an element at a specific position	
		void deleteElement(int position) {
			int *copy = new int[this->index - 1];

			for (int i = 0; i < this->index - 1; i++) {
				if (i == position) {
					continue;
				} else {
					copy[i] = this->A[i];
				}

			}
			this->index--;
			this->A = copy;
		}	

		void reverseArray() {
			int start = 0, end = this->index - 1;

			while (start < end) {
				int temp = this->A[start];
				this->A[start] = this->A[end];
				this->A[end] = temp;
				start++;
				end--;
			}

		}


};

int main() {
	Array *arr = new Array(100);
	arr->push(10);
	arr->push(30);
	arr->push(5);
	arr->push(49);
	arr->push(500);
	arr->printAllElemets();
	arr->reverseArray();
	arr->printAllElemets();

}




