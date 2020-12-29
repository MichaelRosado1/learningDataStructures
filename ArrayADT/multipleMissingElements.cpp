#include <iostream> 

//finds multiple missing elements in an array
void findMissingElements(int arr[], int size) {
	int difference = arr[0];
	//search through every element of the array 
	for (int i = 0; i < size; i++) {
		if (arr[i] - i != difference) {
			while (difference < arr[i] - i) {
				printf("%d\n", i + difference);
				difference++;
			}
		}
	}

}

int main() {
	int arr[] = {6,7,8,9,11,12,15,16,17,18,19};
	findMissingElements(arr, (sizeof(arr)/ sizeof(arr[0])));
}	


