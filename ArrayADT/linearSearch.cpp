#include <iostream>

class Array {
	int *arrayptr;
	int length;
	int index;
	public:
		Array() {
			length = 10;
			index = 0;
			arrayptr = new int[length];
		}

		void push(int element) {
			if (this->index == length - 1) {
				arrayptr = new int[length*=2];
			}
			this->arrayptr[index] = element;
			this->index++;
		}

		void swapElements(int currentPosition, int desiredPosition) {
			int temp = this->arrayptr[currentPosition];
			this->arrayptr[currentPosition] = this->arrayptr[desiredPosition];
			this->arrayptr[desiredPosition] = temp;
		}

		int linearSearch(int element) {
			for (int i = 0; i < this->length; i++) {
				if (this->arrayptr[i] == element) {
					swapElements(i, i - 1);
					return i;
				} 
			}
			return -1;
		}

		void print() {
			for (int i = 0; i < this->length; i++) {
				std::cout<<"Element at " <<i<<" is equal to: "<<this->arrayptr[i];
				std::cout<<"\n";
			}
		}

		
};

int main() {
	Array *myarr = new Array();	
	myarr->push(1);
	myarr->push(2);
	myarr->push(3);
	myarr->push(4);
	myarr->push(5);
	myarr->push(6);
	myarr->push(7);
	myarr->print();
	myarr->linearSearch(6);
	myarr->print();



}
