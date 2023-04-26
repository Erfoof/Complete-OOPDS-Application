#pragma once
#include "Datastructure.h"
#include "DLLNode.h"
class DoubleLinkedList : public Datastructure {
private:
    DLLNode* head;
    DLLNode* tail;
    DLLNode* current;
    int count;
    string Dstype;
public:
    //copy constructor
    DoubleLinkedList(const DoubleLinkedList& other);

    DoubleLinkedList();

    string gettype();

    ~DoubleLinkedList();

    void print();

    bool search(int value);

    void sort_ascend();

    void sort_descend();

    void DLLaddNodeToEnd(int data);

    void DLLdeleteNodeFromEnd();

    void DLLaddNodeToFront(int data);

    void DLLdeleteNodeFromFront();

    void DLLinsertAfter(int data, int value);

    DLLNode* DLLpointToBeginning();

    DLLNode* DLLpointToEnd();

    int DLLgetValueAtPointer(DLLNode* pointer);

    DLLNode* DLLmovePointerForward(DLLNode* pointer);

    DLLNode* DLLmovePointerBackward(DLLNode* pointer);

    bool DLLatEndOfList(DLLNode* pointer);

    bool DLLatHeadOfList(DLLNode* pointer);
};


