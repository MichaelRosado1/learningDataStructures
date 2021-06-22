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

}

