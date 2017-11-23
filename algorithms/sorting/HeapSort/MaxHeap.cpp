#include <iostream>
#include <vector>
#include "MaxHeap.hpp"

void MaxHeap::insert(int data) {
    bst.push_back(data);
    bubbleUp(_size);
    _size++;
}

int MaxHeap::extractMax() {
    if (_size == 0) {
        return 0;
    }
    int MAX = bst[0];
    bst[0] = bst[_size - 1];
    bst.pop_back();
    _size--;
    sinkDown(0);
    return MAX;
}

bool MaxHeap::remove(int data) {
    for (int i = 0; i < _size; i++) {
        if (bst[i] == data) {
            bst[i] = bst[_size - 1];
            bst.pop_back();
            _size--;
            sinkDown(i);
            return true;
        }
    }
    return false;
}


void MaxHeap::sinkDown(int index) {
    while (!isLeafNode(index)) {
        int l = leftChild(index);
        int r = rightChild(index);
        int maxChildIndex = l;
        if (r < _size && bst[r] > bst[l]) {
            maxChildIndex = r;
        }
        if (bst[maxChildIndex] <= bst[index]) {
            break;
        }
        swap(bst[index], bst[maxChildIndex]);
        index = maxChildIndex;
    }
}

void MaxHeap::bubbleUp(int index) {
    while (index > 0 && bst[parent(index)] < bst[index]) {
        swap(bst[parent(index)], bst[index]);
        index = parent(index);
    }
}

bool MaxHeap::isLeafNode(int &index) const {
    return leftChild(index) >= _size;
}

int MaxHeap::parent(int &index) const {
    return (index - 1) / 2;
}
int MaxHeap::leftChild(int &index) const {
    return index * 2 + 1;
}
int MaxHeap::rightChild(int &index) const {
    return index * 2 + 2;
}
void MaxHeap::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
