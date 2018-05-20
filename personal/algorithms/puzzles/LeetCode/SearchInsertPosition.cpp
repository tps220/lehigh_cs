//Thomas Salemy
//Search insert position

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        int index = -1;
        while (right > left) {
            int mid = (left + right) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid;
            }
            else {
                index = mid;
                break;
            }
        }
        if (index == -1) {
            return right;
        }
        return index;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, provide [target] and [array of nums]" << endl;
        return 1;
    }
    
    vector<int> nums;
    int current_num = 0;
    int i = 0;
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
    int target = atoi(argv[1]);

    Solution *run_method = new Solution;
    cout << "Index to insert " << target << " is " << run_method -> searchInsert(nums, target) << endl;
    delete run_method;
    return 0;
}
