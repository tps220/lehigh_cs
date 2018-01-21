//Thomas Salemy
//Longest Common Prefix

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &words) {
        if (words.size() == 0) {
            return "";
        }

        int commonality = words[0].length();
        for (int i = 1; i < words.size(); i++) {
            if (words[i].length() < commonality) {
                commonality = words[i].length();
            }
            int local_match = 0;
            for (int k = 0; k < commonality; k++) {
                if (words[0][k] != words[i][k]) {
                    break;
                }
                local_match++;
            }
            if (local_match == 0) {
                return "";
            }
            else if (local_match < commonality) {
                commonality = local_match;
            }
        }
        return words[0].substr(0, commonality);
    }

    string trulyLongestCommonPrefix(vector<string>& words) {
        if (words.size() == 0) {
            return "";
        }

        sort(words.begin(), words.end());
        int smallest_word_index = 0;
        int smallest_word = words[0].size();

        int critical_index = -1;
        int max_size = 0;
        int first_string_length = smallest_word;
        for (int i = 0; i < words.size() - 1; i++) {
            int commonality = 0;
            int second_string_length = words[i + 1].length();
            for (int k = 0; k < first_string_length && k < second_string_length; k++) {
                if (words[i][k] != words[i + 1][k]) {
                    break;
                }
                commonality++;
            }
            if (commonality > max_size) {
                critical_index = i;
                max_size = commonality;
            }
            if (second_string_length < smallest_word) {
                smallest_word_index = i + 1;
            }
            first_string_length = second_string_length;
        }

        if (critical_index == -1) {
            return words[smallest_word_index];
        }
        string retval = words[critical_index].substr(0, max_size);
        return retval;
    }
};

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Invalid command line arguments, provide at least one string" << endl;
        return 1;
    }
    vector<string> input;
    for (int i = 1; i < argc; i++) {
        input.push_back(argv[i]);
    }
    
    Solution *run_method = new Solution;
    cout << "Longest Common Prefix: " << run_method -> longestCommonPrefix(input) << endl;
    delete run_method;
    return 0;
}
