#include <iostream> 

struct Matrix {
	int a[10];
	int n;
};

void set(struct Matrix *m, int i, int j, int x) {
	if (i == j) {
		m->a[i - 1] = x;
	} 
}

int get(struct Matrix m, int i, int j) {
	if (i == j) {
		return m.a[i-1];
	}
	return 0; 
}

void display(struct Matrix m) {
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			if (i == j) {
				printf("%d ", m.a[i]);
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main() {
	struct Matrix m;
	m.n = 4;

	set(&m,1,1,5);
	set(&m,2,2,8);
	set(&m,3,3,9);
	set(&m,4,4,12);

	display(m);
	printf("%d \n", get(m,2,2));
}
