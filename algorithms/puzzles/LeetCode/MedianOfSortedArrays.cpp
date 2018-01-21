//Thomas Salemy
//Median of Two Sorted Arrays

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &array1, vector<int> &array2) {
        if (array1.size() > array2.size()) {
            return findMedianSortedArrays(array2, array1);
        }
        int k = (array1.size() + array2.size() + 1) / 2;
        return find_median(array1, array2, k, 0, array1.size());
    }
private:
    double find_median(vector<int> &array1, vector<int> &array2, int k, int min, int max) {
        int split_a = (min + max) / 2;
        int split_b = k - split_a;

        if (split_a < max && array2[split_b - 1] > array1[split_a]) {
            return find_median(array1, array2, k, min + 1, max);
        }
        else if (split_a > min && array1[split_a - 1] > array2[split_b]) {
            return find_median(array1, array2, k, min, max - 1);
        }
        else {
            //Find the maximum of the left
            int maximum_of_left;
            if (split_a == 0) {
                maximum_of_left = array2[split_b - 1];
            }
            else if (split_b == 0) {
                maximum_of_left = array1[split_a - 1];
            }
            else {
                if (array2[split_b - 1] >= array1[split_a - 1]) {
                    maximum_of_left = array2[split_b - 1];
                }
                else {
                    maximum_of_left = array1[split_a - 1];
                }
            }
            if ((array1.size() + array2.size()) % 2 == 1) {
                return maximum_of_left;
            }
            //Find min of the right
            int minimum_of_right;
            if (split_a == array1.size()) {
                minimum_of_right = array2[split_b];
            }
            else if (split_b == array1.size()) {
                minimum_of_right = array1[split_a];
            }
            else {
                if (array2[split_b] <= array1[split_a]) {
                    minimum_of_right = array2[split_b];
                }
                else {
                    minimum_of_right = array1[split_a];
                }
            }
            return (maximum_of_left + minimum_of_right) / 2.0;
        }
    }

};

int main(int argc, char** argv) {
    vector<int> start;

}

