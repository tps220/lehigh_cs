#include "HeapSort.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main(int argc, char** argv) {
    
    const int SIZE = 50000;
    int *array = new int[SIZE];
    int *array2 = new int[SIZE];
    srand(400);
    for (int i = 0; i < SIZE; i++) {
        int temp = rand() % 2000000;
        array[i] = temp;
        array2[i] = temp; 
    }

    //Heap Sort Time
    clock_t time = clock();
    heap_sort(array, SIZE);
    clock_t time2 = clock();
    
    //Bubble Sort Time
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (array2[j] < array2[j + 1]) {
                int temp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp;
            }
        }
    }
    clock_t time3 = clock();


    for (int i = 0; i < SIZE - 1; i++) {
        if (array[i] < array[i + 1]) {
            cout << "FAILED" << endl;
            return -1;
        }
    }
    
    cout << "Success. Time: " << (time2 - time) / (double) CLOCKS_PER_SEC << endl;
    cout << "Compared to Bubble Sort Time: " << (time3 - time2) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
