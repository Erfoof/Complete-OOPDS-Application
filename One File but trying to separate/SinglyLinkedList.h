#pragma once
#include "Datastructure.h"
#include "SLLNode.h"
class SinglyLinkedList : public Datastructure {
private:
    SLLNode* head;
    SLLNode* current;
    int count;
    string Dstype;
public:

    string gettype();

    SinglyLinkedList(const SinglyLinkedList& other);

    SinglyLinkedList();

    ~SinglyLinkedList();

    void print();

    bool search(int value);

    void sort_ascend();

    void sort_descend();

    void SLLaddNodeToEnd(int data);

    void SLLdeleteNodeFromEnd();

    void SLLaddNodeToFront(int data);

    void SLLdeleteNodeFromFront();

    void SLLinsertAfter(int data, int value);

    SLLNode* SLLpointToBeginning();

    SLLNode* SLLpointToEnd();

    int SLLgetValueAtPointer(SLLNode* pointer);

    SLLNode* SLLmovePointerForward(SLLNode* pointer);

    bool SLLatEndOfList(SLLNode* pointer);

    bool SLLatHeadOfList(SLLNode* pointer);
};

