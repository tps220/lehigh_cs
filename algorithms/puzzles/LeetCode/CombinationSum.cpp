//Thomas Salemy
//Combination Sum

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > combinations;
		sort(candidates.begin(), candidates.end());
		vector<int> current_sequence;
		sums(candidates, combinations, current_sequence, 0, target, 0);
		return combinations;
	}
private:
	void sums(vector<int> &candidates, vector<vector <int> > &combinations, vector<int> &current_sequence, int current_sum, int &target, int starting_index) {
		if (current_sum == target) {
			combinations.push_back(current_sequence);
			return;
		}
		else if (current_sum > target) {
			return;		
		}
		for (int i = starting_index; i < candidates.size(); i++) {
			current_sequence.push_back(candidates[i]);
			current_sum += candidates[i];
			sums(candidates, combinations, current_sequence, current_sum, target, i);
			current_sum -= candidates[i];
			current_sequence.pop_back();
		}	
	}
};

int main(int argc, char** argv) {
	if (argc != 3) {
		cout << "Invalid command line arguments, provide [target] [array of nums]" << endl;
		return 1;
	}
	int target = atoi(argv[1]);
	int current_num = 0;
	vector<int> nums;
	int i = 0;
	while (argv[2][i] != '\0') {
		if (argv[2][i] == ',') {
			nums.push_back(current_num);
			current_num = 0;
		}
		else {
			current_num = current_num * 10 + argv[2][i] - '0';
		}
		i++;
	}
	nums.push_back(current_num);
	cout << "INPUT" << endl;
	cout << "Target: " << target << endl;
	cout << "Array: ";
	for (int i = 0; i < nums.size(); i++) {
		cout << i << " ";
	}
	cout << endl;
	
	Solution *run_method = new Solution;
	vector<vector<int> > combinations = run_method -> combinationSum(nums, target);
	cout << "Combinations" << endl;
	for (int i = 0; i < combinations.size(); i++) {
		cout << i + 1 << ": (";
		for (int k = 0; k < combinations[i].size(); k++) {
			cout << combinations[i][k];
			if (k != combinations[i].size() - 1) {
				cout << ", ";
			}
		}
		cout << ")" << endl;	
	}
	
	delete run_method;
	return 0;
}
