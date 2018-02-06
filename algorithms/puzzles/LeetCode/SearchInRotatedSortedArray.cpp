//Thomas Salemy
//Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (target <= nums[right] && target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line input, provide [target] and [array of nums separated by commas]" << endl;
        return 1;
    }
    
    int target = atoi(argv[1]);
    vector<int> nums;
    int i = 0;
    int current_num = 0;
    while (argv[2][i] != '\0') {
        if (argv[2][i] == ',') {
            nums.push_back(current_num);
            current_num = 0;
        }
        else {
            current_num = current_num * 10 + argv[2][i] - '0';
        }
        i++;
    }
    nums.push_back(current_num);
    cout << "Starting method" << endl;
    Solution *run_method = new Solution;
    cout << "Searched for " << target << " and found at index " << run_method -> search(nums, target) << endl;
    delete run_method;
    return 0;
}
