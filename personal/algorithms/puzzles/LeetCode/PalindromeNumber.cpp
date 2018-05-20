//Thomas Salemy
//Palindrome Number, determine if a number is
//palindrome without using extra space.
//Typically would do this with a stringstream, but
//this is against the rules of the problem

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x != 0 && x % 10 == 0) {
            return false;
        }

        int sum = 0;
        while (sum < x) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        if (sum == x || sum / 10 == x) {
            return true;
        }
        return false;
    }
};


int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line argument, input [number]" << endl;
        return 1;
    }

    Solution *run_method = new Solution;
    if (run_method -> isPalindrome(atoi(argv[1]))) {
        cout << "The provided number is a palindrome" << endl;
    }
    else {
        cout << "The provided number is not a palindrome" << endl;
    }
    delete run_method;
    return 0;
}
