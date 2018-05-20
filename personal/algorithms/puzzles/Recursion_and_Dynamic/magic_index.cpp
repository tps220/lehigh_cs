//Magic Index is where index number equals the value found at the index
//Determine whether a sorted array has a magic index

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool magicBinarySearch(int* array, int l, int r) {
    if (l <= r) {
        int mid = (l + r) / 2;
        if (array[mid] == mid) {
            cout << "Value: " << array[mid] << " found at index: " << mid << endl;
            return true;
        }
        else if (array[mid] > mid) {
            return magicBinarySearch(array, l, mid - 1);
        }
        return magicBinarySearch(array, mid + 1, r);
    }
    return false;
}

int main(int argc, char** argv) {
    
    int *arr = new int[1000]();
    for (int i = 0; i < 20; i++) {
        arr[i] = i;
    }
    for (int i = 20; i < 1000; i++) {
        arr[i] = i + 1;
    }
    cout << "-----------------" << endl;
    if (magicBinarySearch(arr, 0, 1000)) {
        cout << "Array 1 Passed Test" << endl;
    }
    else {
        cout << "Array 2 Failed Test" << endl;
    }

    int *arr2 = new int[2000]();
    for (int i = 0; i < 2000; i++) {
        arr2[i] = i + 1;
    }
    cout << "-------------------" << endl;
    if (!magicBinarySearch(arr2, 0, 2000)) {
        cout << "Array 2 Passed Test" << endl;
    }
    else {
        cout << "Array 2 Failed Test" << endl;
    }

    cout << "-------------------" << endl;
    cout << "Random Test" << endl;
    vector<int> temp;
    for (int i = 0; i < 5000; i++) {
        temp.push_back(rand() % 2000);
    }
    sort(temp.begin(), temp.end());
    int *arr3 = new int[5000]();
    int counter = 0;
    for (int i = 0; i < 4999; i++) {
        if (temp[i] == temp[i + 1]) {
            continue;
        }
        arr3[counter] = temp[i];
        counter++;
    }
    cout << magicBinarySearch(arr3, 0, counter - 1) << endl;
    delete [] arr;
    delete [] arr2;
    delete [] arr3;
}
