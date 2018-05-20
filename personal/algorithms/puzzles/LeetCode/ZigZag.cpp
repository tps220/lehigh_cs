#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }   
        
        string *tiles = new string[numRows]();
        int step = 1;
        int current_row = 0;
        for (int i = 0; i < s.length(); i++) {
            tiles[current_row].append(1, s[i]);
            current_row += step;
            if (current_row == 0) {
                step = 1;
            }
            else if (current_row == numRows - 1) {
                step = -1;
            }
        }

        s.clear();
        for (int i = 0; i < numRows; i++) {
            s.append(tiles[i]);
        }

        delete [] tiles;
        return s;
    }
};


int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Improper command line arguments, provide [string] [numrows]" << endl;
        return 1;
    }

    string string_to_transform(argv[1]);
    int numRows = atoi(argv[2]);
    Solution run_method;
    cout << run_method.convert(string_to_transform, numRows) << endl;
    return 0;
}
