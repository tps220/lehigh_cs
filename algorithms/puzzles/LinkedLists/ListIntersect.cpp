//Determine whether a linked list has a loop, if it does find the point
//of intersection of that loop
#include <iostream>
#include <vector>

LinkedListNode findIntersection(LinkedListNode* root) {
    if (root == NULL) {
        return NULL;
    }
    LinkedListNode* slow = root;
    LinkedListNode* runner = root;
    //Find intersection inside the loop
    while (runner -> next != NULL && runner -> next -> next != NULL) {
        runner = runner -> next -> next;
        slow = slow -> next;
        if (runner == slow) {
            break;
        }
    }
    //After breaking from while statement, if no intersection return NULL
    if (runner -> next == NULL || runner -> next -> next == NULL) {
        return NULL;
    }
    //Otherwise we have found a loop, and the start of the intersection
    //can be found mathematically by resetting one of the linked list nodes
    //to the head and incrementing both one by one. Their next intersection
    //will be the start of the head
    slow = root;
    while (runner != slow) {
        slow = slow -> next;
        runner = runner -> next;
    }

    return runner;
}
