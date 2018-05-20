//Thomas Salemy
//Remove Nth Node From End of List
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* root, int n) {
        //If empty list return null
        if (!root) {
            return NULL;
        }
        if (n <= 0) {
            return root;
        }

        ListNode* runner = root;
        for (int i = 0; i < n; i++) {
            runner = runner -> next;
            //If n goes beyond the size of the list, return null
            if (!runner && i != n - 1) {
                return root;
            }
        }
        return removeHelper(root, runner);
    }

    //Helper Functions for testing 
    ListNode* delete_list(ListNode* root) {
        if (root == NULL) {
            return root;
        }
        root -> next = delete_list(root -> next);
        delete root;
        return NULL;
    }
    ListNode* printList(ListNode* root) {
        if (root == NULL) {
            return root;
        }
        cout << root -> val << " ";
        root -> next = printList(root -> next);
        return root;
    }

private:
    //Helper function for removeNthFromEnd function
    ListNode* removeHelper(ListNode* root, ListNode* runner) {
        if (runner == NULL) {
            ListNode* temp = root -> next;
            delete root;
            return temp;
        }
        root -> next = removeHelper(root -> next, runner -> next);
        return root;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, provide [nth from end to delete] and [linked list elements]" << endl;
        return 1;
    }
    
    //Set up problem from user input
    int n = atoi(argv[1]);
    
    ListNode* ll = new ListNode(0);
    ListNode* runner = ll;
    int current_value = 0;
    int i = 0;
    while (argv[2][i] != '\0') {
        if (argv[2][i] == ',') {
            runner -> next = new ListNode(current_value);
            runner = runner -> next;
            current_value = 0;
        }
        else {
            current_value = current_value * 10 + argv[2][i] - '0';
        }
        i++;
    }
    runner -> next = new ListNode(current_value);
    runner = ll;
    ll = ll -> next;
    delete runner;
    
    
    //Run target methods and print results
    Solution *run_method = new Solution;
    cout << "Old List" << endl;
    ll = run_method -> printList(ll);

    ll = run_method -> removeNthFromEnd(ll, n);
    cout << endl << "New List" << endl;
    ll = run_method -> printList(ll);
    cout << endl;
    
    //Clean up
    ll = run_method -> delete_list(ll);
    delete run_method;

}
