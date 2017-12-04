Partition the linked list so that all the values
less than a key is before all the values that are bigger

void partition(LinkedListNode* node, int val) {
    if (node == NULL) {
        return false;
    }
    //Search for element to make sure it's in the list, if that's
    //a necessary requirement
    LinkedListNode* runner = node;
    while (runner -> next != NULL && runner -> next -> data != val) {
        runner = runner -> next;
    }
    //Did not find value we wanted in the list
    if (runner -> next == NULL) {
        return false;
    }
    
    runner = node;
    while (root != NULL && swapper != NULL) {
        if (root -> data < val) {
            int temp = swapper -> data;
            swapper -> data = root -> data;
            root -> val = swapper -> val;
            swapper = swapper -> next;
        }
        root = root -> next;
    }

}

//Or, simply use the pointers two create two lists, one less than
//and one greater than or equal to and insert the nodes into there
//as we iterate through the list
void partitionB(LinkedListNode*& node, int val) {
    if (node == NULL) {
        return false;
    }
    LinkedListNode *headBegin;
    LinkedListNode *headEnd;

    LinkedListNode *tailBegin;
    LinkedListNode *tailEnd;

    while (node != NULL) {
        if (node -> data > val) {
            if (tailBegin == NULL) {
                tailBegin = node;
                tailEnd = tailBegin;
            }
            else {
                tailEnd -> next = node;
                tailEnd = tailEnd -> next;
            }
        }
        else {
            if (headBegin == NULL) {
                headBegin = node;
                headEnd = headBegin;
            }
            else {
                headEnd -> next = node;
                headEnd = headEnd -> next;
            }
        }
    }
    if (headBegin == NULL) {
        return tailBegin;
    }
    if (tailBegin == NULL) {
        return headBegin;
    }
    tailEnd -> next = NULL;
    headEnd -> next = tailBegin;
    return headBegin;
}
