//Thomas Salemy
//Container with most water

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int begin = 0;
        int end = height.size() - 1;
        int MAX = 0;
        while (end > begin) {
            //Find minimum height of two posts
            int min_height = height[end];
            if (height[begin] < min_height) {
                min_height = height[begin];
            }
            //Find area of two and check if greater than current max
            int area = min_height * (end - begin);
            if (area > MAX) {
                MAX = area;
            }
            //Find which post to change based on which one is smaller
            if (height[begin] > height[end]) {
                end--;
            }
            else {
                begin++;
            }
        }
        return MAX;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments, provide [height of posts] seperated by commas" << endl;
        return 1;
    }
    vector<int> height;
    int i = 0;
    int current_val = 0;
    while (argv[1][i] != '\0') {
        if (argv[1][i] == ',') {
            height.push_back(current_val);
            current_val = 0;
        }
        else {
            current_val = current_val * 10 + argv[1][i] - '0';
        }
        i++;
    }
    height.push_back(current_val);

    Solution *run_method = new Solution;
    cout << "Max Area: " << run_method -> maxArea(height) << endl;
    delete run_method;

    return 0;
}
