//Thomas Salemy
//Quicksort tester

#include <iostream>
#include "QuickSort.hpp"
using namespace std;

int main(int argc, char** argv) {
    const int SIZE = 100000;
    int *array = new int[SIZE];
    srand(1282);
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000000;
    }

    clock_t time = clock();
    quicksort(array, SIZE);
    clock_t time2 = clock();

    for (int i = 0; i < SIZE - 1; i++) {
        if (array[i] > array[i + 1]) {
            cout << "Failed" << endl;
            return -1;
        }
    }

    cout << "Sucess" << endl;
    cout << "Time: " << (time2 - time) / (double)CLOCKS_PER_SEC << endl;
    
    delete [] array;  
    return 0;
}
