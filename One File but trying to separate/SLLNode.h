#pragma once
class SLLNode {
public:
    int data;
    SLLNode* next;
    SLLNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
