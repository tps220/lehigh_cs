#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int n = atoi(argv[1]);
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    long long *paths = new int[n + 1];
    paths[0] = 1;
    paths[1] = 1;
    paths[2] = 2;
    paths[3] = 3;
    for (int i = 3; i <= n; i++) {
        paths[i] = paths[i - 1] + paths[i - 2] + paths[i - 3];
    }
    long long answer = paths[n];
    delete [] paths;
}
