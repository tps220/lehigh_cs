//Thomas Salemy
//Search For A Range

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) {
            return vector<int>(2, -1);
        }
        int lower_bound = binarySearch(nums, target - 0.5, false);
        int higher_bound = binarySearch(nums, target + 0.5, true);
        if (lower_bound == nums.size() || nums[lower_bound] != target) {
            return vector<int>(2, -1);
        }
        vector<int> retval;
        retval.push_back(lower_bound);
        retval.push_back(higher_bound);
        return retval;
    }
    int binarySearch(vector<int> &nums, double target, bool toggle) {
        int low = 0;
        int high = nums.size();
        while (high > low) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            //will never be found since comparing a double and int
        }
        if (toggle) {
            return high - 1;
        }
        return low;
    }
};

//Test
int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, provide [target] [array of numbers separated by commas]" << endl;
        return 1;
    }
    int target = atoi(argv[1]);
    vector<int> nums;
    int current_val = 0;
    int i  = 0;
    while (argv[2][i] != '\0') {
        if (argv[2][i] == ',') {
            nums.push_back(current_val);
            current_val = 0;
        }
        else {
            current_val = current_val * 10 + argv[2][i] - '0';
        }
        i++;
    }
    nums.push_back(current_val);

    Solution *run_method = new Solution;
    vector<int> ans = run_method -> searchRange(nums, target);
    cout << "Answer: " << ans[0] << " through " << ans[1] << endl;
    int start = -1, end = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            end = i;
            if (start == -1) {
                start = i;
            }
        }
    }
    if (ans[0] == start && ans[1] == end) {
        cout << "Passed, answer is " << start << " through " << end << endl;
    }
    else {
        cout << "Failed, real answer is " << start << " through " << end << endl;
    }
    delete run_method;
    return 0;
}
