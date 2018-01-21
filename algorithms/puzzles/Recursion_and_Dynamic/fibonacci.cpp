#include <iostream>
#include <stdlib.h>
using namespace std;

unsigned long fibonacci(int number, unsigned long* array) {
    if (number == 0) {
        array[0] = 0;
        return 0;
    }
    else if (number == 1) {
        array[1] = 1;
        return 1;
    }
    fibonacci(number - 1, array);
    array[number] = array[number - 1] + array[number - 2];
    return array[number];
}



int main(int argc, char** argv) {
    if (argc != 2) {
        return 1;
    }
    int number = atoi(argv[1]);
    unsigned long *hash = new unsigned long[number + 1]();
    cout << "Result: " << fibonacci(number, hash) << endl;
    delete [] hash;
}
