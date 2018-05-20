//Thomas Salemy
//Reverse Integer

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse (int x) {
        long retval = 0;
        while (x != 0) {
            retval = retval * 10 + x % 10;
            x /= 10;
        }
        if (retval > INT_MAX || retval < INT_MIN) {
            return 0;
        }
        return (int)retval;
    }
};


int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments, input [number]" << endl;
        return 1;
    }
    int input = atoi(argv[1]);
    Solution *run_method = new Solution;
    cout << "The number " << input << " reversed is: " << run_method -> reverse(input) << endl;
    delete run_method;
    return 0;
}
