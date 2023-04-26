#include "SinglyLinkedList.h"
//----------------------------SLL:

//constructor
SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    current = nullptr;
    count = 0;
    Dstype = "sll";
}

//copy constructor
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) {
    head = nullptr;
    current = nullptr;
    count = 0;
    SLLNode* temp = other.head;
    while (temp != nullptr) {
        SLLaddNodeToEnd(temp->data);
        temp = temp->next;
    }
}



//returns the type of DS

string SinglyLinkedList::gettype() {
    return Dstype;
};


//destructor
SinglyLinkedList:: ~SinglyLinkedList() {
    SLLNode* temp = head;
    while (temp != nullptr) {
        SLLNode* next = temp->next;
        delete temp;
        temp = next;
    }
}

void SinglyLinkedList::print() {
    SLLNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool SinglyLinkedList::search(int value) {
    SLLNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void SinglyLinkedList::sort_ascend() {
    SLLNode* temp = head;
    while (temp != nullptr)
    {
        for (SLLNode* i = temp->next; i != nullptr; i = i->next) {
            if (temp->data > i->data) {
                int tempData = temp->data;
                temp->data = i->data;
                i->data = tempData;
            }
        }
        temp = temp->next;
    }
}

void SinglyLinkedList::sort_descend() {
    SLLNode* temp = head;
    while (temp != nullptr)
    {
        for (SLLNode* i = temp->next; i != nullptr; i = i->next) {
            if (temp->data < i->data) {
                int tempData = temp->data;
                temp->data = i->data;
                i->data = tempData;
            }
        }
        temp = temp->next;
    }
}

//Add a node from the end
void SinglyLinkedList::SLLaddNodeToEnd(int data) {
    SLLNode* newNode = new SLLNode(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        SLLNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count++;
}
//Delete a node from the end
void SinglyLinkedList::SLLdeleteNodeFromEnd() {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        current = nullptr;
    }
    else {
        SLLNode* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    count--;
}
//Add a node from the front
void SinglyLinkedList::SLLaddNodeToFront(int data) {
    SLLNode* newNode = new SLLNode(data);
    newNode->next = head;
    head = newNode;
    count++;
}
//Delete a node from the front
void SinglyLinkedList::SLLdeleteNodeFromFront() {
    if (head == nullptr) {
        return;
    }
    SLLNode* temp = head;
    head = head->next;
    delete temp;
    count--;
}
//insert a value after a node value
void SinglyLinkedList::SLLinsertAfter(int data, int value) {
    SLLNode* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            SLLNode* newNode = new SLLNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            count++;
            return;
        }
        temp = temp->next;
    }
}
//Point a poiter to the beginning of the list
SLLNode* SinglyLinkedList::SLLpointToBeginning() {
    current = new SLLNode(0);
    current = head;
    return current;
}
//Point a poiter to the end of the list
SLLNode* SinglyLinkedList::SLLpointToEnd() {
    current = new SLLNode(0);
    current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}
//getting value at pointer
int SinglyLinkedList::SLLgetValueAtPointer(SLLNode* pointer) {
    return pointer->data;
}

//moving pointer forward
SLLNode* SinglyLinkedList::SLLmovePointerForward(SLLNode* pointer) {
    if (pointer->next != nullptr) {
        pointer = pointer->next;
        return pointer;
    }
    return nullptr;
}

//Check if pointer is at the end of the list
bool SinglyLinkedList::SLLatEndOfList(SLLNode* pointer) {
    if (pointer->next == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
//Check if pointer is at the head of the list
bool SinglyLinkedList::SLLatHeadOfList(SLLNode* pointer) {
    if (pointer == head) {
        return true;
    }
    else {
        return false;
    }
}
