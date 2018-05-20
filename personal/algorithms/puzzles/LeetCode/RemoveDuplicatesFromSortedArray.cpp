//Thomas Salemy
//Remove Duplicates from Sorted Array
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
            if (i != nums.size()) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main(int argc, char** argv) {
    cout << "Testing randomly" << endl;
    vector<int> nums;
    for (int i = 0; i < 200; i++) {
        nums.push_back(rand() % 50);
    }
    sort(nums.begin(), nums.end());
    Solution *run_method = new Solution;
    int index = run_method -> removeDuplicates(nums);
    cout << "The following array has length " << index << endl;
    for (int i = 0; i < 200; i++) {
        cout << nums[i];
        if (i % 50 == 0 && i != 0) {
            cout << endl;
        }
    }
    cout << endl;
    delete run_method;
    return 0;
}
