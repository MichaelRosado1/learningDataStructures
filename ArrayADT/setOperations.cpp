#include <cstdlib>
#include <iostream>
struct Array {
	int a[10];
	int size;
	int length;
};

struct Array *intersection(struct Array *arr1, struct Array *arr2) {
	int i,j,k;
	i = j = k = 0;

	struct Array *arr3 = (struct Array *)std::malloc(sizeof(struct Array));

	while (i < arr1->length) {
		if (j == arr1->length) {
			i++;
			j = 0;
		}
		if (arr1->a[i] == arr2->a[j]) {
			arr3->a[k] = arr1->a[i]; 
			k++;
			i++;
			j = 0;
		} 
		j++;
	}
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}
struct Array *setUnion(struct Array *arr1, struct Array *arr2) {
	int i, j, k;
	i = j = k = 0;
	struct Array *arr3 = new Array();

	while (i < arr1->length && j < arr2->length) {
		if (arr1->a[i] < arr2->a[j]) {
			arr3->a[k] = arr1->a[i];
			k++;
			i++;
		} else if (arr2->a[j] < arr1->a[i]) {
			arr3->a[k]= arr2->a[j];
			k++;
			j++;
		} else {
			arr3->a[k] = arr1->a[i];	
			j++;
			k++;
			i++;
		}
	}
	for (; i < arr1->length; i++) {
		arr3->a[k++] = arr1->a[i];
	}
	
	for (; j < arr2->length; j++) {
		arr3->a[k++] = arr2->a[j];
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}
int main() {
	struct Array arr1 = {{1,2,3,4,5}, 10, 5};
	
	struct Array arr2 = {{1,3,5,20,200}, 10, 5};

	struct Array *arr3;

	arr3 = setUnion(&arr1, &arr2);

	for (int i = 0; i < arr3->length; i++) {
		std::cout<<arr3->a[i]<<std::endl;
	}
}
