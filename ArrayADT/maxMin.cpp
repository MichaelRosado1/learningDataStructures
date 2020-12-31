#include <iostream>

struct Array {
	int a[10];
	int length;
	int size;
};

void findMinMax(struct Array arr) {
	int min = arr.a[0];
	int max = arr.a[0];	

	for (int i = 1; i < arr.length; i++) {
		if (arr.a[i] < min) {
			min = arr.a[i];
		} else if (arr.a[i] > max) {
			max = arr.a[i];
		} else {
			continue;
		}
	}

	std::cout<<"Min value: "<<min<<" max value: "<<max<<"\n";
}

int main() {
	struct Array arr = {{1,2,3,4,5,6,7,8,9,10},10,9};
	struct Array arr2 = {{23,24,25,55,49,200,19,-3,-100,10}, 10,9};

	
	findMinMax(arr);

	findMinMax(arr2);


}
