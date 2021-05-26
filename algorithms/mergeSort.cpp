#include <iostrem>
#include <vector>

using namespace std;


void merge(vector<int>array, int l, int m, int r) {

}

void mergeSort(vector<int> array, int l, int r) {
    //if the indices are equal to each other, then we have already sorted the halves
    if (l >= r) {
        //we should do nothing
        return;
    }

    int median = l + (r-l) / 2
    
    //we want to break down the two halves
    mergeSort(array, l, median);
    mergeSort(array, median + 1, r);
    
    //we then reconstruct the array in the merge function
    merge(array, l, m, r);
}


int main() {

    vector<int> arr = {12,11,13,5,4,8};

    int arraySize = arr.size();

    //passing in the array, leftside and rightside inidices
    mergeSort(arr, 0, arraySize - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }

}
