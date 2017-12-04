//Implement a method to find the kth to last element
//of a linked list
//


//Iteratively
//Use two nodes, and start to increment one node
//after we have reached the kth time of incrementing
//the other node
int kthToLastElement(LinkedListNode* root, int k) {
    if (root == NULL) {
        return 0;
    }
    LinkedListNode* runner = root;
    for (int i = 0; i < k; i++) {
        if (root -> next == NULL) {
            return 0;
        }
        runner = runner -> next;
    }
    while (runner -> next != NULL) {
        root = root -> next;
        runner = runner -> next;
    }
    return root -> data;
}





