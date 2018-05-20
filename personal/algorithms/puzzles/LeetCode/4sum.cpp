//Thomas Salemy
//4 Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > retval;
        if (nums.size() < 4) {
            return retval;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int k = i + 1; k < nums.size() - 2; k++) {
                int critical = target - nums[i] - nums[k];
                int begin = k + 1;
                int end = nums.size() - 1;
                while (end > begin) {
                    int sum = nums[begin] + nums[end];
                    if (sum > critical) {
                        end--;
                    }
                    else if (sum < critical) {
                        begin++;
                    }
                    else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[begin]);
                        temp.push_back(nums[end]);
                        retval.push_back(temp);
                        while (end > begin && nums[end] == temp[3]) {
                            end--;
                        }
                        while (begin < end && nums[begin] == temp[2]) {
                            begin++;
                        }
                    }
                }
                while (k < nums.size() - 2 && nums[k] == nums[k + 1]) {
                    k++;
                }
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return retval;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, provide [target] and [array of numbers] separated by commas" << endl;
        return 1;
    }
    int target = atoi(argv[1]);
    int current_val = 0;
    vector<int> input;
    int i = 0;
    while (argv[2][i] != '\0') {
        if (argv[2][i] == ',') {
            input.push_back(current_val);
            current_val = 0;
        }
        else {
            current_val = current_val * 10 + argv[2][i] - '0';
        }
        i++;
    }
    input.push_back(current_val);

    Solution *run_method = new Solution;
    vector<vector<int> > set = run_method -> fourSum(input, target);
    cout << "Solution of numbers that add to " << target << endl;
    for (int i = 0; i < set.size(); i++) {
        cout << i + 1 << ": ";    
        for (int k = 0; k < set[i].size(); k++) {
            cout << set[i][k] << " ";
        }
        cout << endl;
    }
    delete run_method;
    return 0;
}
