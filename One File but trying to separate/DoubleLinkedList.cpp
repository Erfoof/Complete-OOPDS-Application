#include "DoubleLinkedList.h"
//----------------------------DLL:
//constructor
DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    count = 0;
    Dstype = "dll";
}

//copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other) {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    count = 0;
    DLLNode* temp = other.head;
    while (temp != nullptr) {
        DLLaddNodeToEnd(temp->data);
        temp = temp->next;
    }
}

//returns DS type
string DoubleLinkedList::gettype() {
    return Dstype;
};

DoubleLinkedList :: ~DoubleLinkedList() {
    DLLNode* temp = head;
    while (temp != nullptr) {
        DLLNode* next = temp->next;
        delete temp;
        temp = next;
    }
}

void DoubleLinkedList::print() {
    DLLNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool DoubleLinkedList::search(int value) {
    DLLNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DoubleLinkedList::sort_ascend() {
    DLLNode* temp = head;
    while (temp != nullptr) {
        DLLNode* next = temp->next;
        while (next != nullptr) {
            if (temp->data > next->data) {
                int tempData = temp->data;
                temp->data = next->data;
                next->data = tempData;
            }
            next = next->next;
        }
        temp = temp->next;
    }
}

void DoubleLinkedList::sort_descend() {
    DLLNode* temp = head;
    while (temp != nullptr) {
        DLLNode* next = temp->next;
        while (next != nullptr) {
            if (temp->data < next->data) {
                int tempData = temp->data;
                temp->data = next->data;
                next->data = tempData;
            }
            next = next->next;
        }
        temp = temp->next;
    }
}


//add node to the end
void DoubleLinkedList::DLLaddNodeToEnd(int data) {
    DLLNode* newNode = new DLLNode(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}


//delete node from the end
void DoubleLinkedList::DLLdeleteNodeFromEnd() {
    if (head == nullptr) {
        return;
    }
    if (head == tail) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
    else {
        DLLNode* temp = tail->prev;
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }
    count--;
}

//add node to the front
void DoubleLinkedList::DLLaddNodeToFront(int data) {
    DLLNode* newNode = new DLLNode(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

//delete node from the front of the list
void DoubleLinkedList::DLLdeleteNodeFromFront() {
    if (head == nullptr) {
        return;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        DLLNode* temp = head->next;
        delete head;
        head = temp;
        head->prev = nullptr;
    }
    count--;
}

//Insert value after a node value.
void DoubleLinkedList::DLLinsertAfter(int data, int value) {
    DLLNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            DLLNode* newNode = new DLLNode(data);
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == tail) {
                tail = newNode;
            }
            else {
                newNode->next->prev = newNode;
            }
            count++;
            return;
        }
        temp = temp->next;
    }
}

////point a pointer to the beginning. (A new pointer will be created whenever this is callled. the pointer name will be decided on the user's PTRName input)
DLLNode* DoubleLinkedList::DLLpointToBeginning() {
    current = new DLLNode(0);
    current = head;
    return current;
}


//point a pointer to the end. (A new pointer will be created whenever this is callled. the pointer name will be decided on the user's PTRName input)
DLLNode* DoubleLinkedList::DLLpointToEnd() {
    current = new DLLNode(0);
    current = tail;
    return current;
}

//get the value at pointer and print it out
int DoubleLinkedList::DLLgetValueAtPointer(DLLNode* pointer) {
    return pointer->data;
}
//move a pointer forward
DLLNode* DoubleLinkedList::DLLmovePointerForward(DLLNode* pointer) {
    if (pointer->next != nullptr) {
        pointer = pointer->next;
        return pointer;
    }
    return nullptr;
}

//move a pointer backward
DLLNode* DoubleLinkedList::DLLmovePointerBackward(DLLNode* pointer) {
    if (pointer->prev != nullptr) {
        pointer = pointer->prev;
        return pointer;
    }
    return nullptr;
}

//Checks if pointer is at the end of the list
bool DoubleLinkedList::DLLatEndOfList(DLLNode* pointer) {
    if (pointer == tail) {
        return true;
    }
    return false;
}

//Checks if pointer is at the head of the list
bool DoubleLinkedList::DLLatHeadOfList(DLLNode* pointer) {
    if (pointer == head) {
        return true;
    }
    return false;
}

