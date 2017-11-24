//Thomas Salemy
//Binary Search Implementation
#include "BinarySearch.hpp"

//Assumes ascending order
bool binarySearch(int *array, int data, unsigned int size) {
    return bsearch(array, data, 0, size - 1);
}

bool bsearch(int *array, int data, int l, int r) {
    if (r >= l) {
        int mid = (r + l) / 2;
        if (array[mid] == data) {
            return true;
        }
        else if (array[mid] > data) {
            return bsearch(array, data, l, mid - 1);
        }
        else {
            return bsearch(array, data, mid + 1, r);
        }
    }
    return false;
}
