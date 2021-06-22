#include <iostream> 
#include <vector>
using namespace std;

void print(vector<int> array) {
    cout<<"{ ";
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i];
        if (i == array.size() - 1) { 
            cout<<" ";
        } else {
            cout<<" , ";
        }
    }
    cout<<" } ";
}

void countSort(vector<int> &array) {
    int maxVal = 0;
    int minVal = 0;
    for (int i = 0; i < array.size();i++) {
        maxVal = max(maxVal, array[i]); 
        minVal = min(minVal, array[i]);
    }

    vector<int> count(maxVal - minVal + 1), output(array.size());

    for (int i = 0; i < array.size(); i++) {
        count[array[i] - minVal]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; i--) {
        output[count[array[i] - minVal] - 1] = array[i];
        count[array[i] - minVal]--;
    }
    for (int i = 0; i < array.size(); i++) {
        array[i] = output[i];
    }

}

int main() {
    //initialize a vector of arbitrary integers
    vector<int> arr;
    arr.push_back(29);
    arr.push_back(14);
    arr.push_back(1);
    arr.push_back(9);
    arr.push_back(18);
    arr.push_back(89);

    print(arr);

    countSort(arr);

    print(arr);
}

