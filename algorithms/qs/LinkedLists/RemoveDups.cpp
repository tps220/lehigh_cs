//Write code to remove duplicates from an unsorted linked lsit
//First question to ask, dealing with a linked list or doubly linked list?
void removeDups() {
    removeDups(this -> head);
}

void removeDups(Node *&root) {
    if (root == NULL) {
        return;
    }
    map<int> buffer;
    buffer.insert(root -> data);
    while (root -> next != NULL) {
        if (buffer.get(root -> next -> data) != buffer.end()) {
            Node* temp = root -> next;
            root -> next = root -> next -> next;
            delete temp;
        }
        else {
            buffer.put(root -> next -> data);
            root = root -> next;
        }
    }
}

//If we can't use a buffer, sort the linked list
//or use a runner to go from current position to onwards
void removeDups(Node*& root) {
    //Helper function that implements
    //merge sort with linked lists
    if (root == NULL) {
        return;
    }
    sort(root);
    while (root -> next != NULL) {
        if (buffer -> next -> data == buffer -> data) {
            Node* temp = root -> next;
            root -> next = root -> next -> next;
            delete temp;
        }
        else {
            root = root -> next;
        }
    }
}
