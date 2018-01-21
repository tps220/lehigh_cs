//Thomas Salemy
//Swap Nodes In Pairs

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* ll = new ListNode(0);
        ListNode* new_list = ll;
        ListNode* old_list = head;
        ListNode* temp;
        bool exited_normal = true;
        while (old_list -> next != NULL) {
            //Preserve the node two links ahead
            temp = old_list -> next -> next;
            //Set values
            new_list -> next = old_list -> next;
            new_list -> next -> next = old_list;
            //Update linked list nodes
            new_list = new_list -> next -> next;
            if (temp == NULL) {
                exited_normal = false;
                break;
            }
            old_list = temp;
        }
        if (exited_normal) {
            new_list -> next = old_list;
        }
        else {
            new_list -> next = NULL;
        }
        old_list = ll;
        ll = ll -> next;
        delete old_list;
        return ll;
    }
    ListNode* createList(char* arguments) {
        ListNode* ll = new ListNode(0);
        ListNode* runner = ll;
        int current_value = 0;
        int i = 0;
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
        runner -> next = new ListNode(current_value);
        runner = ll;
        ll = ll -> next;
        delete runner;
        return ll;
    }
    ListNode* deleteList(ListNode* root) {
        if (root == NULL) {
            return root;
        }
        root -> next = deleteList(root -> next);
        delete root;
        return NULL;
    }
    ListNode* printList(ListNode* root) {
        if (root == NULL) {
            return root;
        }
        cout << root -> val  << " ";
        root -> next = printList(root -> next);
        return root;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments, input [data values separated by comma]" << endl;
    }
    //Create linked list
    Solution *run_method = new Solution;
    ListNode* data = run_method -> createList(argv[1]);
    data = run_method -> printList(data);
    cout << endl;
    //Run target method  
    data = run_method -> swapPairs(data);
    data = run_method -> printList(data);
    cout << endl;
    data = run_method -> deleteList(data);
    return 0;
}
