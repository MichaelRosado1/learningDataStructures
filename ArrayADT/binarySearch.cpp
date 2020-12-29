#include <iostream> 

struct Array {
	int a[10];
	int length; 
	int size;
};

void binarySearch(struct Array arr, int searchKey) {
	int low, mid, high;
	low = 0;
	high = arr.length - 1;

	while (low <= high) {
		//middle of the array
		mid = (low + high) / 2;

		//if the key is at the middle of the array
		if (searchKey == arr.a[mid]) {
			//print the middle index
			std::cout<<"Element("<<searchKey<<") was found at position: "<<mid;
			//(For a sorted array) if the key is less than the middle position
			//return to prevent infinite printing
			return;
		} else if (searchKey < arr.a[mid]) {
			// move the high num down to reduce the search range
			high = mid - 1;
		} else {
			// else increase the low number to reduce search range since num is above mid point
			low = mid + 1;
		}
	}
}
int main() {
	struct Array arr = {{1,2,3,5,7,8,22,33,23,100}, 11, 10};

	binarySearch(arr,23);
}
