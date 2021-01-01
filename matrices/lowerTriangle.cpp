#include <iostream> 

class lowerTri {
	private:
		int *a;
		int n;
	public:
		lowerTri() {
			this->a = new int[2*(2+1)/2];
			this->n = 2;
		}
		lowerTri(int n) {
			this->n = n;
			this->a = new int[n*(n+1)/2];
		}

		~lowerTri() {
			delete []this->a;
		}
		void set(int i, int j, int x) {
			if (i >= j) {
				this->a[i*(i-1)/2 + j - 1] = x;
			}
		}

		int get(int i, int j) {
			if (i >= j) {
				return this->a[i*(i-1)/2+j-1];
			}
			return 0;
		}

		void display() {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= this->n; j++) {
					if (i >= j) {
						std::cout<<this->a[i*(i-1)/2+j-1]<<" ";
					}
				}
				std::cout<<"\n";
			}
		}
		int getDimension() {
			return this->n;
		}
};


int main() {
	int d;
	std::cout<<"enter dimensions\n";
	std::cin>>d;
	lowerTri lm(d);

	int x;

	std::cout<<"enter all elements\n";
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= d; j++) {
			std::cin>>x;
			lm.set(i,j,x);
		}
	}

	lm.display();

	lm.getDimension();
}
