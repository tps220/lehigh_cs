//Thomas Salemy
//Add Two Numbers, represented backwards by a linked list
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* delete_linkedlist(ListNode* root) {
    if (root == NULL) {
        return root;
    }
    root -> next = delete_linkedlist(root -> next);
    delete root;
    return NULL;
}
void printList(ListNode* root) {
    while (root != NULL) {
        cout << root -> val;
        root = root -> next;
    }
}
class Solution {
public:
    //Given two non-empty linked lists, so ignore corner cases of empty lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int adder = l1 -> val + l2 -> val;
        int carryover = adder / 10;
        ListNode* result = new ListNode(adder % 10);
        ListNode* runner = result;
        l1 = l1 -> next;
        l2 = l2 -> next;
        adder = 0;

        while (l1 != NULL || l2 != NULL || carryover > 0) {
            //If first list node not null, store its value
            if (l1) {
                adder = l1 -> val;
                l1 = l1 -> next;
            }
            //If second list node not null, store its value
            if (l2) {
                adder += l2 -> val;
                l2 = l2 -> next;
            }
            //Store the carryover value
            adder += carryover;
            
            //Update the linked list node in creation with the value
            runner -> next = new ListNode(adder % 10);
            runner = runner -> next;
            //Update the carryover value
            carryover = adder / 10;
            //Reset adder to zero for next sequence
            adder = 0;
        }
        return result;
    }


};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, input [number 1] and [number 2]" << endl;
        return 1;
    }

    //Create linked lists for test cases
    int first_num = atoi(argv[1]);
    int second_num = atoi(argv[2]);
    ListNode* l1 = new ListNode(first_num % 10);
    first_num /= 10;
    ListNode* runner = l1;
    while (first_num != 0) {
        runner -> next = new ListNode(first_num % 10);
        first_num /= 10;
        runner = runner -> next;
    }

    ListNode* l2 = new ListNode(second_num % 10);
    second_num /= 10;
    runner = l2;
    while (second_num != 0) {
        runner -> next = new ListNode(second_num % 10);
        second_num /= 10;
        runner = runner -> next;
    }

    Solution *run_method = new Solution;
    ListNode* solution = run_method -> addTwoNumbers(l1, l2);
    
    //Print answer
    runner = l1;
    printList(runner);
    cout << " + ";
    runner = l2;
    printList(runner);
    cout << " = ";
    runner = solution;
    printList(runner);
    cout << endl;

    delete_linkedlist(l1);
    delete_linkedlist(l2);
    delete_linkedlist(solution);
    delete run_method;
    return 0;
}
