//Thomas Salemy
//Remove Element

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int index = nums.size();
        int i = 0;
        while (index > i) {
            if (nums[i] == val) {
                nums[i] = nums[index - 1];
                index--;
            }   
            else {
                i++;
            }
        }
        return index;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments, input [target value]" << endl;
        return 1;
    }
    int value = atoi(argv[1]);
    if (value > 10) {
        cout << "Target value must be less than or equal to 10" << endl;
        return 1;
    }

    vector<int> nums;
    for (int i = 0; i < 200; i++) {
        nums.push_back(rand() % 11);
    }
    sort(nums.begin(), nums.end());
    Solution *run_method = new Solution;
    int index = run_method -> removeElement(nums, value);
    cout << "Removed " << index << " elements of value " << value << endl;
    cout << "Contents: " << endl;
    for (int i = 0; i < index; i++) {
        if (i != 0 && i % 25 == 0) {
            cout << endl;
        }
        cout << nums[i] << " ";
    }
    cout << endl;
    delete run_method;
    return 0;
}
