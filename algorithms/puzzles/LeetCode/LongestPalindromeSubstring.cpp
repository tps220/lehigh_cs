//Thomas Salemy
//Longest Palindrome Substring

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_palindrome = "";
        int MAX = 0;
        for (int i = 0; i < s.length(); i++) {
            //Check odd palindrome
            int width = palindrome_width(s, i, i);
            if (width > MAX) {
                longest_palindrome = s.substr(i - width / 2, width); 
                MAX = width;
            }
            //Check even palindrome
            if (i < s.length() - 1 && s[i] == s[i + 1]) {
                width = palindrome_width(s, i, i + 1);
                if (width > MAX) {
                    longest_palindrome = s.substr(i - width / 2 + 1, width);
                    MAX = width;
                }
            }
        }
        return longest_palindrome;
    }
private:
    int palindrome_width(string &s, int begin, int end) {
        while (begin >= 0 && end < s.length())  {
            if (s[begin] != s[end]) {
                break;
            }
            begin--;
            end++;
        } 
        return end - begin - 1;
    }
};


int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments" << endl;
        return 1;
    }

    string input(argv[1]);
    Solution *run_method = new Solution;
    cout << "Longest Palindrome Substring: " << run_method -> longestPalindrome(input) << endl;
    delete run_method;
}
