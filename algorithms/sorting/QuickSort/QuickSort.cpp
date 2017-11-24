#include "QuickSort.hpp"
#include <iostream>
void quicksort(int *array, unsigned int size) {
    qsort(array, 0, size - 1);
}

void qsort(int *array, int l, int r) {
    if (r > l) {
        int divider = partition(array, l, r);
        qsort(array, l, divider - 1);
        qsort(array, divider + 1, r);
    }
}

int partition(int *array, int l, int r) {
    //Determine pivot value through median of three
    int mid = (l + r) / 2;
    if (array[mid] >= array[l]) {
        if (array[mid] <= array[r]) {
            swap(array[mid], array[r]);
        }
    }
    else if (array[l] <= array[r]) {
        swap(array[l], array[r]);
    }
    int pivot = r;
    
    //Implement main quick sort algorithm
    int k = l;
    for (int i = l; i <= r; i++) {
        if (array[i] <= array[pivot]) {
            swap(array[i], array[k]);
            k++;
        }
    }
    return k - 1;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
