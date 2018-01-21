//Thomas Salemy
//3 Sum Closest

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //Corner cases
        if (nums.size() == 0) {
            return 0;
        }
        else if (nums.size() == 1) {
            return nums[0];
        }
        else if (nums.size() == 2) {
            return nums[0] + nums[1];
        }
        sort(nums.begin(), nums.end());
        int final_sum = 0;
        int closest_difference = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            //Find number to search for
            int critical = target - nums[i];
            //Search for two numbers in the set that come closest to that new target
            int sum = search(nums, critical, i + 1, nums.size() - 1) + nums[i];
            //Check to see if closest difference to sum
            if (abs(sum - target) < closest_difference) {
                closest_difference = abs(sum - target);
                final_sum = sum;
            }
        }
        return final_sum;
    }
private:
    int search(vector<int>& nums, int target, int begin, int end) {
        int local_final_sum = 0;
        int local_closest_difference = INT_MAX;
        while (begin < end) {
            int sum = nums[begin] + nums[end];
            //See if absolute value of sum is less than closest local difference found so far
            if (abs(sum - target) < local_closest_difference) {
                local_closest_difference = abs(sum - target);
                local_final_sum = sum;
            }
            //Based on relative value of sum, adjust bounds
            if (sum == target) {
                return sum;
            }
            if (sum < target) {
                begin++;
            }
            else {
                end--;
            }
        }
        return local_final_sum;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, provide [target], then [array of nums] separated by comma" << endl;
        return 1;
    }
    int target = atoi(argv[1]);
    vector<int> input;
    int current_value = 0;
    int i = 0;
    while (argv[2][i] != '\0') {
        if (argv[2][i] == ',') {
            input.push_back(current_value);
            current_value = 0;
        }
        else {
            current_value = current_value * 10 + argv[2][i] - '0';
        }
        i++;
    }
    input.push_back(current_value);
    
    Solution *run_method = new Solution;
    cout << "Closest to target " << target << " is: " << run_method -> threeSumClosest(input, target) << endl;
    delete run_method;
    return 0;
}
