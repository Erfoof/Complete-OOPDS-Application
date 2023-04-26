#pragma once
class DLLNode {
public:
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
