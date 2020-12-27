#include <cstdlib>
#include <iostream>
struct Array {
	int a[10];
	int size;
	int length;
};

struct Array *arrUnion(struct Array *arr1, struct Array *arr2) {
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
int main() {
	struct Array arr1 = {{1,2,3,4,5}, 10, 5};
	
	struct Array arr2 = {{1,3,5,20,200}, 10, 5};

	struct Array *arr3;

	arr3 = arrUnion(&arr1, &arr2);

	for (int i = 0; i < arr3->length; i++) {
		std::cout<<arr3->a[i]<<std::endl;
	}
}
