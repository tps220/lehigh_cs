//Thomas Salemy
//Merge Two Sorted Lists
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return NULL;
        }

        ListNode* merged_list = new ListNode(0);
        ListNode* runner = merged_list;
        
        while (l1 || l2) {
            if (l1 && !l2) {
                runner -> next = l1;
                l1 = l1 -> next;
                runner = runner -> next;
            }
            else if (!l1 && l2) {
                runner -> next = l2;
                l2 = l2 -> next;
                runner = runner -> next;
            }
            else if (l1 -> val > l2 -> val) {
                runner -> next = l2;
                l2 = l2 -> next;
                runner = runner -> next;
            }
            else {
                runner -> next = l1;
                l1 = l1 -> next;
                runner = runner -> next;
            }
        }
        runner = merged_list;
        merged_list = merged_list -> next;
        delete runner;
        return merged_list;
    }

    ListNode* generateList(char* arguments) {
        ListNode* root = new ListNode(0);
        ListNode* runner = root;
        int i = 0;
        int current_value = 0;
        while (arguments[i] != '\0') {
            if (arguments[i] == ',') {
                runner -> next = new ListNode(current_value);
                runner = runner -> next;
                current_value = 0;
            }
            else {
                current_value = current_value * 10 + arguments[i] - '0';
            }
            i++;
        }
        runner = root;
        root = root -> next;
        delete runner;
        return root;
    }
    ListNode* printList(ListNode *root) {
        if (root == NULL) {
            return NULL;
        }
        cout << root -> val << " ";
        root -> next = printList(root -> next);
        return root;
    }
    ListNode* delete_list(ListNode* root) {
        if (root == NULL) {
            return NULL;
        }
        root -> next = delete_list(root -> next);
        delete root;
        return NULL;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, need [sorted data set 1] and [sorted data set 2]" << endl;
        return 1;
    }

    //Run test on given input, assuming data already sorted
    Solution *run_method = new Solution;
    ListNode* l1 = run_method -> generateList(argv[1]);
    ListNode* l2 = run_method -> generateList(argv[2]);
    ListNode* answer = run_method -> mergeTwoLists(l1, l2);
    answer = run_method -> printList(answer);
    cout << endl;
   
    //Clean up data
    answer = run_method -> delete_list(answer);
    delete run_method;
}
