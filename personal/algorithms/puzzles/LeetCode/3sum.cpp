//Thomas Salemy
//Find all unique triples in the array which gives the sum of zero,
//no duplicate triplets allowed

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > retval;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            int target = nums[i] * -1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;   
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    vector<int> insertion;
                    insertion.push_back(nums[i]);
                    insertion.push_back(nums[left]);
                    insertion.push_back(nums[right]);
                    retval.push_back(insertion);
                    do {
                        left++;
                    } while (left < nums.size() - 1 && nums[left] == insertion[1]);

                    do {
                        right--;   
                    } while (right > 0 && nums[right] == insertion[2]);                    
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return retval;
    }
};


int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line argument, input [set of numbers] separated by commas" << endl;
        return 1;
    }
    vector<int> set;
    int curr_val = 0;
    int i = 0;
    bool negative = false;
    while (argv[1][i] != '\0') {
        if (argv[1][i] == ',') {
            if (negative) {
                curr_val *= -1;
            }
            set.push_back(curr_val);
            curr_val = 0;
            negative = false;
        }
        else if (argv[1][i] == '-') {
            negative = true;
        }
        else {
            curr_val = curr_val * 10 + argv[1][i] - '0';
        }
        i++;
    }
    set.push_back(curr_val);

    Solution *run_method = new Solution;
    vector<vector<int> > answer = run_method -> threeSum(set);
    cout << "Answer: " << endl;
    if (answer.size() == 0) {
        cout << "Empty" << endl;
    }
    else {
        for (int i = 0; i < answer.size(); i++) {
            for (int k = 0; k < answer[i].size(); k++) {
                cout << answer[i][k] << ", ";
            }
            cout << endl;
        }
    }
    delete run_method;
    return 0;
}

