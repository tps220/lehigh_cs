//Thomas Salemy
//Max Heap
#include <vector>
#include <iostream>

class MaxHeap {
    public:
        //Constructor/Destructor
        MaxHeap() : _size(0), bst() {}
        ~MaxHeap() {}
        
        //Heap Methods
        void insert(int data);
        int extractMax();
        bool remove(int data);
        
        //Getters
        unsigned int size();

    private:
        std::vector<int> bst;
        unsigned int _size;

        //Helper Methods
        void sinkDown(int index);
        void bubbleUp(int index);
        bool isLeafNode(int &index) const;
        int parent(int &index) const;
        int leftChild(int &index) const;
        int rightChild(int &index) const;
        void swap(int &a, int &b);
};
