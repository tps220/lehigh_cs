#include "MaxHeap.hpp"
#include "HeapSort.hpp"
//Default heap_sort is descending order
void heap_sort(int* array, unsigned int size) {
    maxheap_sort(array, size);
}

//descending order sort
void maxheap_sort(int* array, unsigned int size) {
    MaxHeap *heap = new MaxHeap();
    for (int i = 0; i < size; i++) {
        heap -> insert(array[i]);
    }
    for (int i = 0; i < size; i++) {
        array[i] = heap -> extractMax();
    }
}

//ascending order sort
void minheap_sort(int* array, unsigned int size) {
    MaxHeap *heap = new MaxHeap();
    for (int i = 0; i < size; i++) {
        heap -> insert(array[i]);
    }
    for (int i = size - 1; i >= 0; i--) {
        array[i] = heap -> extractMax();
    }
}
