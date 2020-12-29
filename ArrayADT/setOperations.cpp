#include <cstdlib>
#include <iostream>
struct Array {
	int a[10];
	int size;
	int length;
};

struct Array *intersection(struct Array *arr1, struct Array *arr2) {
	/*
		i -> index for arr1
		j -> index for arr2
		k -> index for new array
	   */
	int i,j,k;
	i = j = k = 0;

	struct Array *arr3 = (struct Array *)std::malloc(sizeof(struct Array));

	//for the length of the array
	while (i < arr1->length) {
		//if the all elements in arr2 have been checked
		if (j == arr1->length) {
		//increment i since there are no matching results
			i++;
		//set j to 0 to check arr2 for a matching result to arr1 at i++
			j = 0;
		}
		//if arr1 at index i is equal to an element in arr2
		if (arr1->a[i] == arr2->a[j]) {
			//add this element to the new array
			arr3->a[k] = arr1->a[i]; 
			//increment k and i to move to next number
			k++;
			i++;
			//set j to 0 to compare elements again
			j = 0;
		} else {
			//else increment j to compare j++ to arr1 at i
			j++;
		}
	}
	//set the length of the new array
	arr3->length = k;
	//set the size of the new array
	arr3->size = 10;
	return arr3;
}
struct Array *setUnion(struct Array *arr1, struct Array *arr2) {
	//i, j, and k used to keep track of arr1[i] arr2[j] and arr3[k]
	int i, j, k;
	i = j = k = 0;
	struct Array *arr3 = new Array();

	//while there are still elements to compare in both arrays
	while (i < arr1->length && j < arr2->length) {
		//similar to merging two arrays
		//comparing element at arr1[i] is less than arr2[j]	
		if (arr1->a[i] < arr2->a[j]) {
			//add arr1[i] to the new array
			arr3->a[k] = arr1->a[i];
			//increment k and i to next position
			k++;
			i++;
			//else if the arr2[j] element is smaller
		} else if (arr2->a[j] < arr1->a[i]) {
			//add arr2[j] to the new array
			arr3->a[k]= arr2->a[j];
			//increment k and j
			k++;
			j++;
		} else {
			//else add the element at arr1[i] to the new array
			arr3->a[k] = arr1->a[i];	
			j++;
			k++;
			i++;
		}
	}
	//add the rest of the first array to the new array
	for (; i < arr1->length; i++) {
		arr3->a[k++] = arr1->a[i];
	}

	//add the rest of the second array to the new array	
	for (; j < arr2->length; j++) {
		arr3->a[k++] = arr2->a[j];
	}

	//set other properties of the array
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array *setDifference(struct Array *arr1, struct Array *arr2) {
	//return a new array with the contents of arr1 - the intersection and arr2
	int i,j,k;
	i = j = k = 0;

	struct Array *arr3 = new Array();


	while (i < arr1->length && j < arr2->length) {
		if (arr1->a[i] < arr2->a[j]) {
			arr3->a[k++] = arr1->a[i++];
		} else if (arr2->a[j] < arr1->a[i]) {
			j++;
		} else {
			i++;
			j++;
		}
	}

	for (; i < arr1->length; i++) {
		arr3->a[k++] = arr1->a[i];
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

/*
   finds the complement of set arr1 
		-> everything except elements in set a and teh intersection of set a 
		and b
	
	{1,2,3}  {1,2,3,4,5,6}
	complement -> {4,5,6}
*/
struct Array* compliment(struct Array* arr1, struct Array* arr2) {
	struct Array * intersectionArr = intersection(arr1, arr2);
	struct Array *arr3 = new Array();
	int i,j,k;
	i = j = k = 0;
	//check if any elements of the intersection are in arr2
	while (i < arr2->length && j < intersectionArr->length) {
		if (j == intersectionArr->length - 1) {
			arr3->a[k] = arr2->a[i];
			k++;
			i++;
			j = 0;
		}
		if (arr2->a[i] == intersectionArr->a[j]) {
			j = 0;
			i++;
		} else {
			j++;
		}
	}
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}
int main() {
	struct Array arr1 = {{1,2,3,4,5}, 10, 5};
	
	struct Array arr2 = {{1,3,5,20,200}, 10, 5};

	struct Array *arr3;

	arr3 = compliment(&arr1, &arr2);

	for (int i = 0; i < arr3->length; i++) {
		std::cout<<arr3->a[i]<<std::endl;
	}
}
