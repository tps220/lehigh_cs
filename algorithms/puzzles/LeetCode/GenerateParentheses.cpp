//Thomas Salemy
//Generate Parentheses

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParentheses(int n) {
        vector<string> retval;
        generateParentheses(retval, "", n, n);
        return retval;
    }
private:
    void generateParentheses(vector<string> &set, string current, int open, int close) {
        if (open == 0 && close == 0) {
            set.push_back(current);
            return;
        }
        if (open > 0) {
            generateParentheses(set, current + '(', open - 1, close);
        }
        if (close > open) {
            generateParentheses(set, current + ')', open, close - 1);
        }
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments, input [number of brackets]" << endl;
        return 1;
    }

    Solution *run_method = new Solution;
    vector<string> set = run_method -> generateParentheses(atoi(argv[1]));
    for (int i = 0; i < set.size(); i++) {
        cout << set[i] << endl;
    }

    delete run_method;
    return 0;
}
