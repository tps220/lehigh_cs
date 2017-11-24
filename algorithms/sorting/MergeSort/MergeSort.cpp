//Thomas Salemy
//Merge Sort Implementation
#include "MergeSort.hpp"

void merge(int *array, int begin, int mid, int end) {
    int left = begin;
    int right = mid + 1;
    int k = 0;
    int *sortedArray = new int[end - begin + 1];
    for (int i = begin; i <= end; i++) {
        if (right > end) {
            sortedArray[k] = array[left];
            left++;
        }
        else if (left > mid) {
            sortedArray[k] = array[right];
            right++;
        }
        else if (array[left] < array[right]) {
            sortedArray[k] = array[left];
            left++;
        }
        else {
            sortedArray[k] = array[right];
            right++;
        }
        k++;
    } 
    for (int i = 0; i < k; i++) {
        array[i + begin] = sortedArray[i];
    }
}

void merge_sort(int *array, int l, int r) {
    if (r > l) {
        int mid = (l + r) / 2;
        merge_sort(array, l, mid);
        merge_sort(array, mid + 1, r);
        merge(array, l, mid, r);
    }
}
