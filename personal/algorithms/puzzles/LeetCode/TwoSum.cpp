//Thomas Salemy
//Two Sum

#include <unordered_map>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> retval;
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.find(nums[i]) != hashmap.end()) {
                retval.push_back(hashmap[nums[i]]);
                retval.push_back(i);
                break;
            }
            hashmap.insert(make_pair<int, int>(target - nums[i], i));
        }
        return retval;
    }
};


int main(int argc, char** argv) {
    //Check validity of command line arguments
    if (argc != 2 && argc != 3) {
        cout << "Invalid command line arguments" << endl;
        cout << "Option 1: Provide single argument to specify a target for a random test" << endl;
        cout << "Option 2: Provide two arguments of order [target val] [integer array seperated by commas]" << endl;
        return 1;
    }

    Solution *run_method = new Solution;
    vector<int> retval;
    vector<int> arr;
    int target;
    //If only one command line argument provided, user is asking for a random test on a given target value
    if (argc == 2) {
        target = atoi(argv[1]);
        for (int i = 0; i < 200; i++) {
            arr.push_back(rand() % 1000);
        }
        retval = run_method -> twoSum(arr, target);
    }
    else {
        //Get command line input
        target = atoi(argv[1]);
        int i = 0;
        int current_val = 0;
        while (argv[2][i] != NULL) {
            if (argv[2][i] == ',') {
                arr.push_back(current_val);
                current_val = 0;
            }
            else {
                current_val *= 10;
                current_val += argv[2][i] - '0';
            }
            i++;
        }
        arr.push_back(current_val);

        //Run method
        retval = run_method -> twoSum(arr, target);
    }

    if (retval.size() == 2) {
       cout << "The vales " << arr[retval[0]] << " and " << arr[retval[1]] << " sum to " << target << endl;
    }
    else {
        cout << "Could not find any values that sum to " << target << endl;
    }
    delete run_method;
    return 0;
}

