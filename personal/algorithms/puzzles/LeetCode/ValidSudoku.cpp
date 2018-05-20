//Thomas Salemy
//Valid Sudoku
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        //Initialize row, column, box flags
        bool **mapper_row = new bool*[10];
        bool **mapper_column = new bool*[10];
        bool **mapper_box = new bool*[10];
        for (int i = 0; i < 10; i++) {
            mapper_row[i] = new bool[10]();
            mapper_column[i] = new bool[10]();
            mapper_box[i] = new bool[10]();
        }

        bool valid = true;
        for (int i = 0; i < board.size(); i++) {
            for (int k = 0; k < board[i].size(); k++) {
                char curr = board[i][k];
                if (curr != '.') {
                    if (mapper_row[i][curr - '0'] || mapper_column[k][curr - '0'] || mapper_box[(i / 3) * 3 + k / 3][curr - '0']) {
                        valid = false;
                        break;
                    }
                    mapper_row[i][curr - '0'] = true;
                    mapper_column[k][curr - '0'] = true;
                    mapper_box[(i / 3) * 3 + k / 3][curr - '0'] = true;
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            delete [] mapper_row[i];
            delete [] mapper_column[i];
            delete [] mapper_box[i];
        }
        delete [] mapper_row;
        delete [] mapper_column;
        delete [] mapper_box;
        return valid;
    }
};

int main(int argc, char** argv) {
    vector<vector<char> > board;
    for (int i = 0; i < 9; i++) {
        board.push_back(vector<char>());
        for (int k = 0; k < 10; k++) {
            board[i].push_back(rand() % 9 + 1 + '0');
        }
    }
    cout << "BOARD SHOULD BE INVALID" << endl;
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 10; k++) {
            cout << board[i][k] - '0';
        }
        cout << endl;
    }
    Solution *run_method = new Solution;
    cout << "Valid Board: " << run_method -> isValidSudoku(board) << endl;
    return 0;
}
