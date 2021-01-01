#include <iostream> 

class DiagonalMatrix {
	private:
		int *arr;
		int n;
	public:
		DiagonalMatrix() {
			//2x2 matrix
			this->n = 2;
			arr = new int[this->n];
		}
		DiagonalMatrix(int n) {
			this->n = n;
			this->arr = new int[n];
		}
		~DiagonalMatrix() {
			delete []arr;
		}
		void set(int i, int j, int x) {
			if (i == j) {
				this->arr[i-1] = x;
			}	
		}

		int get(int i, int j) {
			if (i == j) {
				return this->arr[i - 1];
			}
			return 0;
		}

		void display() {
			for (int i = 0; i < this->n; i++) {
				for (int j = 0; j < this->n; j++) {
					if (i == j) {
						std::cout<<this->arr[i]<<" ";
					} else {
						std::cout<<"0 ";
					}
				}
				std::cout<<"\n";
			}
		}
};



int main() {
	DiagonalMatrix m(4);
	m.set(1,1,5);
	m.set(2,2,8);
	m.set(3,3,9);
	m.set(4,4,12);

	m.display();
}
