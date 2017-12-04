//Delete a node in the middle of a singly linked list

//Copy the next node's value into the current,
//and destroy the last node
void deleteMiddleVal(LinkedListNode node) {
    //If we are at the tail, we are not a middle value.
    //And this can not be done, therefore, we must do nothing
    if (node == NULL || node -> next == NULL) {
        return;
    }
    node -> data = node -> next -> data;
    LinkedListNode temp = node -> next;
    node -> next = node -> next -> next;
    delete temp;
}
