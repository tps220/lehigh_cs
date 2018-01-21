//Thomas Salemy
//Letter Combinations of a Phone Number

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>();
        }
        vector<string> map;
        map.push_back(" ");
        map.push_back("");
        map.push_back("abc");
        map.push_back("def");
        map.push_back("ghi");
        map.push_back("jkl");
        map.push_back("mno");
        map.push_back("pqrs");
        map.push_back("tuv");
        map.push_back("wxyz");
        
        vector<string> retval;
        retval.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            int current_num = digits[i] - '0';
            vector<string> temp;
            for (int k = 0; k < retval.size(); k++) {
                for (int j = 0; j < map[current_num].size(); j++) {
                    temp.push_back(retval[k] + map[current_num][j]);
                }
            }
            retval.swap(temp);
        }
        return retval;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments, input [digits of phone number] " << endl;
        return 1;
    }
    string digits(argv[1]);
    Solution *run_method = new Solution;
    cout << "COMBINATIONS" << endl;
    vector<string> combinations = run_method -> letterCombinations(digits);
    for (int i = 0; i < combinations.size(); i++) {
        cout << combinations[i] << endl;
    }
    delete run_method;
    return 0;
}
