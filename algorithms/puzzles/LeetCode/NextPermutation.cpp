//Thomas Salemy
//Next Permutation

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        //Find index to swap
        int swap_a = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                swap_a = i;
                break;
            }
        }
        //If no index found, must be in descending order
        //and must reverse into ascending order
        if (swap_a == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int swap_b = swap_a + 1;
        for (int i = nums.size() - 1; i > swap_a + 1; i--) {
            if (nums[i] > nums[swap_a]) {
                swap_b = i;
                break;
            }
        }
        swap(nums[swap_a], nums[swap_b]);
        reverse(nums.begin() + swap_a + 1, nums.end());
    }
    void nextPermutationInitial(vector<int> &nums) {
        int index = nums.size() - 2;
        bool swapped = false;
        while (index >= 0) {
            int i = index + 1;
            int swap_index = -1;
            int smallest_found = INT_MAX;
            while (i < nums.size()) {
                if (nums[i] > nums[index]) {
                    if (swap_index == -1) {
                        smallest_found = nums[i];
                        swap_index = i;
                    }
                    else if (nums[i] <= smallest_found) {
                        smallest_found = nums[i];
                        swap_index = i;
                    }
                }
                i++;
            }
            if (swap_index != -1) {
                swap(nums[swap_index], nums[index]);
                swapped = true;
                break;
            }
            index--;
        }
        if (!swapped) {
            sort(nums.begin(), nums.end());
        }
    }
private:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments" << endl;
        return 1;
    }
    vector<int> nums;
    int current_num = 0;
    int i = 0;
    while (argv[1][i] != '\0') {
        if (argv[1][i] == ',') {
            nums.push_back(current_num);
            current_num = 0;
        }
        else {
            current_num += argv[1][i] - '0';
        }
        i++;
    }
    nums.push_back(current_num);

    Solution *run_method = new Solution;
    run_method -> nextPermutation(nums);
    cout << "Answer: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;
    delete run_method;
    return 0;
}
