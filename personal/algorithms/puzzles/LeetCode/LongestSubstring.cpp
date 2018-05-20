//Thomas Salemy
//Longest Substring Without Repeating Characters

#include <iostream>
#include <string>
using namespace std;

class Solution {
public: 
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        //Assume string contains only chars of extended ascii
        int *charmap = new int[256]();
        int MAX = 1;
        int begin = 1;
        charmap[s[0]] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (charmap[s[i]] >= begin) {
                begin = charmap[s[i]] + 1;
            }
            else if (i + 2 - begin > MAX) {
                MAX = i + 2 - begin;
            }
            charmap[s[i]] = i + 1;
        }
        delete [] charmap;
        return MAX;
    }
};


int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line input" << endl;
        return 1;
    }
    string input(argv[1]);
    Solution *run_method = new Solution;
    cout << "Longest substring without repeating characters: " << run_method -> lengthOfLongestSubstring(input) << endl;
    delete run_method;
}
