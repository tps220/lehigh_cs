#include "BinarySearch.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    const int SIZE = 100000;
    int *array = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
    }
    
    srand(1210);
    for (int i = 0; i < 10; i++) {
        int data = rand() % 200000;
        bool found = binarySearch(array, data, SIZE);
        if (found) {
            if (data >= 100000) {
                cout << "False positive. Failed" << endl;
                return -1;
            }
            cout << "Found " << data << endl;
        }
        else {
            if (data < 100000) {
                cout << "False Negative. Failure" << endl;
                return -1;
            }
            cout << "Did not find " << data << endl;
        }
    }
    
    delete [] array;

}
