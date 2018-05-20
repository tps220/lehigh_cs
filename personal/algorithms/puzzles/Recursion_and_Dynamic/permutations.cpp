//Thoams Salemy
//Implemenmting a backtracking approach towards finding all permutations
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void permutationsHelper(string &word, vector<string> &list, int start, int n) {
    if (start == n - 1) {
        list.push_back(word);
        return;
    }
    for (int i = start; i < n; i++) {
        swap(word[start], word[i]);
        permutationsHelper(word, list, start + 1, n);
        swap(word[start], word[i]);
    }
}

vector<string> permutations(string word) {
    vector<string> retval;
    permutationsHelper(word, retval, 0, word.length());
    return retval;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        return 1;
    }

    string word(argv[1]);
    vector<string> perms = permutations(word);
    for (int i = 0; i < perms.size(); i++) {
        cout << perms[i] << endl;
    }

}
