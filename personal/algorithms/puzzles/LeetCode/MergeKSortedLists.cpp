//Thomas Salemy
//Merge K Sorted Lists

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        while (lists.size() > 1) {
            ListNode* temp = merge(lists[0], lists[1]);
            lists.erase(lists.begin(), lists.begin() + 2);
            lists.push_back(temp);
        }
        return lists[0];
    }

    //Helper functions for testing
    ListNode* createSortedList(vector<int> &data) {
        if (data.size() == 0) {
            return NULL;
        }
        sort(data.begin(), data.end());
        ListNode* ll = new ListNode(data[0]);
        ListNode* runner = ll;
        for (int i = 1; i < data.size(); i++) {
            runner -> next = new ListNode(data[i]);
            runner = runner -> next;
        }
        return ll;
    }
    bool confirmSorted(ListNode* ll) {
        if (ll == NULL) {
            return true;
        }
        ListNode* runner = ll;
        while (runner -> next != NULL) {
            if (runner -> val > runner -> next -> val) {
                return false;
            }
            runner = runner -> next;
        }
        return true;
    }
    ListNode* deleteList(ListNode* root) {
        if (root == NULL) {
            return NULL;
        } 
        ListNode* temp;
        while (root -> next != NULL) {
            temp = root;
            root = root -> next;
            delete temp;
        }
        delete root;
        return NULL;
    }
private:
    ListNode* merge(ListNode* l1, ListNode *l2) {
        if (!l1 && !l2) {
            return NULL;
        }
        ListNode* merged = new ListNode(0);
        ListNode* runner = merged;
        while (l1 || l2) {
            if (!l1) {
                runner -> next = l2;
                break;
            }
            else if (!l2) {
                runner -> next = l1;
                break;
            }
            else if (l1 -> val < l2 -> val) {
                runner -> next = l1;
                l1 = l1 -> next;
            }
            else {
                runner -> next = l2;
                l2 = l2 -> next;
            }
            runner = runner -> next;
        }
        runner = merged;
        merged = merged -> next;
        delete runner;
        return merged;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments, input [number of lists to create of size 50]" << endl;
        return 1;
    }

    int size = atoi(argv[1]);
    Solution *run_method = new Solution;

    vector<ListNode*> data;
    for (int i = 0; i < size; i++) {
        vector<int> temp;
        for (int i = 0; i < 50; i++) {
            temp.push_back(rand() % 100000);
        }
        data.push_back(run_method -> createSortedList(temp));
    }
    
    ListNode* answer = run_method -> mergeKLists(data);
    if (run_method -> confirmSorted(answer)) {
        cout << "List has been merged and sorted properly" << endl;
    }
    else {
        cout << "List was NOT merged and sorted properly" << endl;
    }
    answer = run_method -> deleteList(answer);
    delete run_method;
    return 0;
}
