//Thomas Salemy
//Reverse Nodes in K-Group

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public: 
    ListNode* reverseKGroup(ListNode* list, int k) {
        int size_of_list = 0;
        list = size(list, size_of_list);
        if (k > size_of_list || k <= 1) {
            return list;
        }
        size_of_list = (size_of_list / k) * k;
        ListNode* ll = NULL;
        ListNode* chain_begin = NULL;
        ListNode* head = list;
        ListNode* target = list -> next;
        for (int i = 0; i < size_of_list; i += k) {
            
            ListNode* previous = head;
            target = head -> next;
            for (int j = 1; j < k; j++) {
                ListNode* next_node = target -> next;
                ListNode* old_head = head;
                head = target;
                head -> next = old_head;
                previous -> next = next_node;
                target = next_node;
            }
            if (i == 0) {
                ll = head;
            }
            else {
                chain_begin -> next = head;
            }
            chain_begin = previous;
            head = previous -> next;
        }
        return ll;
    }

    //Helper functions for testing
    ListNode* printList(ListNode* list) {
        if (list == NULL) {
            return list;
        }
        cout << list -> val << " ";
        list -> next = printList(list -> next);
        return list;
    }
    ListNode* createList(char* arguments) {
        ListNode* ll = new ListNode(0);
        ListNode* runner = ll;
        int current_val = 0;
        int i = 0;
        while (arguments[i] != '\0') {
            if (arguments[i] == ',') {
                runner -> next = new ListNode(current_val);
                runner = runner -> next;
                current_val = 0;
            }
            else {
                current_val = current_val * 10 + arguments[i] - '0';
            }
            i++;
        }
        runner -> next = new ListNode(current_val);
        runner = ll;
        ll = ll -> next;
        delete runner;
        return ll;
    }
    ListNode* deleteList(ListNode* list) {
        if (list == NULL) {
            return list;
        }
        list -> next = deleteList(list -> next);
        delete list;
        return NULL;
    }
private:
    ListNode* size(ListNode* list, int &counter) {
        if (list == NULL) {
            return list;
        }
        list -> next = size(list -> next, ++counter);
        return list;
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Invalid command line arguments, input [value of k] and [data values of linked list separated by commas]" << endl;
        return 1;
    }
    Solution *run_method = new Solution;
    int k = atoi(argv[1]);
    ListNode* data = run_method -> createList(argv[2]);
    data = run_method -> printList(data);
    cout << endl;
    data = run_method -> reverseKGroup(data, k);
    data = run_method -> printList(data);
    cout << endl;
    data = run_method -> deleteList(data);
    delete run_method;
    return 0;
}
