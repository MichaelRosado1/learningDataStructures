#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>array, int l, int m, int r) {
    int left = m - l + 1;
    int right = r - m;
    vector<int> leftArr;
    vector<int> rightArr;
    leftArr.resize(left);
    rightArr.resize(right);

    for (int i = 0; i < left; i++) {
        leftArr[i] = array[l + i];
    }
    for (int i = 0; i < right; i++) {
        rightArr[i] = array[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;


    //while in bounds
    while (i < left && j < right) {
        if (leftArr[i] <= rightArr[j]) {
            array[k] = rightArr[i];
            i++;
        } else {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < left) {
        array[k] = leftArr[i];
        i++;
        k++;
    }
 
    while (j < right) {
        array[k] = rightArr[j];
        j++;
        k++;
    } 
}

void mergeSort(vector<int> array, int l, int r) {
    //if the indices are equal to each other, then we have already sorted the halves
    if (l >= r) {
        //we should do nothing
        return;
    }

    int median = l + (r-l) / 2;
    
    //we want to break down the two halves
    mergeSort(array, l, median);
    mergeSort(array, median + 1, r);
    
    //we then reconstruct the array in the merge function
    merge(array, l, median, r);
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
