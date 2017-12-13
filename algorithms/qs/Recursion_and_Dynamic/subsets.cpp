//Thomas Salemy
//Generate all subsets
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;


void generateSubsets(vector<vector<int> > &list, vector<int> &nums, vector<int> set, int start) {
    list.push_back(set);  
    for (int i = start; i < nums.size(); i++) {
        set.push_back(i);
        generateSubsets(list, nums, set, i + 1);
        set.pop_back();
    }
}

vector< vector<int> > subsets(vector<int> set) {
    vector< vector<int> > retval;
    vector<int> list;
    generateSubsets(retval, set, list, 0);
    return retval;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        return 1;
    }
    
    vector<int> nums;
    for (int i = 0; i < strlen(argv[1]); i++)  {
        nums.push_back(argv[1][i] - '0');
    }

    vector< vector<int> > sets = subsets(nums);
    for (int i = 0; i < sets.size(); i++) {
        cout << "[";
        for (int k = 0; k < sets[i].size(); k++) {
            cout << sets[i][k] << " ";
        }
        cout << "]" << endl;
    }
}

