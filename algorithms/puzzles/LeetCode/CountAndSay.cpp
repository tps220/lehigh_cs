//Thomas Salemy
//Count and Say

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) {
			return "1";
		}
		else if (n == 2) {
			return "11";
		}
		string sequence = "11";
		for (int i = 3; i <= n; i++) {
			string current_sequence = "";
			int count = 1;
			for (int j = 1; j < sequence.length(); j++) {
				if (sequence[j - 1] != sequence[j]) {
					current_sequence.append(1, count + '0');
					current_sequence.append(1, sequence[j - 1]);
					count = 0;
				}
				count++;
			}
			current_sequence.append(1, count + '0');
			current_sequence.append(1, sequence[sequence.length() - 1]);
			sequence = current_sequence;
		}
		return sequence;
	}
};

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Invalid command line arguments, provide [int n]" << endl;
		return 1;
	}
	int n = atoi(argv[1]);
	Solution *run_method = new Solution;
	cout << "Answer for " << n << ": " << run_method -> countAndSay(n) << endl;
	delete run_method;
	return 0;
}
