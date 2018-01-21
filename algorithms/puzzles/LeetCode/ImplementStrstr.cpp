//Thomas Salemy
//Implement Strstr

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strstr(string haystack, string needle) {
        for (int i = 0; i < (int)haystack.length() - (int)needle.length() + 1; i++) {
            int k = 0;
            while (k < needle.length()) {
                if (haystack[i + k] != needle[k]) {
                    break;
                }
                k++;
            }
            if (k == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, input [haystack] [needle]" << endl;
        return 1;
    }
    string haystack(argv[1]);
    string needle(argv[2]);
    Solution *run_method = new Solution;
    int index = run_method -> strstr(haystack, needle);
    if (index != -1) {
        cout << "Found " << needle << " at index " << index << " of " << haystack << endl;
        bool valid = true;
        for (int i = index; i < index + needle.size() && i < haystack.size(); i++) {
            if (haystack[i] != needle[i - index]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "Test passed" << endl;
        }
        else {
            cout << "Failed test" << endl;
        }
    }
    else {
        cout << "Could not find " << needle << " inside " << haystack << endl;
    }       
    delete run_method;
    return 0;
}
