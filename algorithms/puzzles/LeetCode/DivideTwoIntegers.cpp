//Thomas Salemy
//Divide Two Integers

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int divide(int divid, int divis) {
        //Handle corner case
        if (divid == INT_MIN && divis == -1) {
            return INT_MAX;
        }
        bool negative = (divid ^ divis) < 0;
        long dividend = abs((long)divid);
        long divisor = abs((long)divis);
        //Begin algorithm
        int retval = 0;
        while (dividend - divisor >= 0) {
            long subtractor = divisor;
            long counter = 1;
            while ((subtractor << 1 ) <= dividend) {
                subtractor<<=1;
                counter<<=1;
            }
            dividend = dividend - subtractor;
            retval += counter;
        }
        if (negative) {
            return -retval;
        }
        return retval;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, provide [dividend] and [divisor]" << endl;
        return 1;
    }
    int dividend = atoi(argv[1]);
    int divisor = atoi(argv[2]); 
    Solution* run_method = new Solution;
    cout << dividend << " divided by " << divisor << " is " << run_method -> divide(dividend, divisor) << endl;
    delete run_method;
    return 0;
}
