#pragma once
#include "Datastructure.h"
class Stack :public Datastructure {
private:
    vector<int> arr;
    string Dstype;
public:
    // Constructor
    Stack();

    string gettype();

    // copy constructor
    Stack(const Stack& other);

    // Destructor
    ~Stack();

    // Push item
    void Stackpush(int item);
    // Pop item
    void Stackpop();

    // Display top of the stack
    int Stacktop();

    // Check if stack is full
    bool StackisFull();

    // Check if stack is empty
    bool StackisEmpty();

    // Print stack
    void print();

    // Search stack
    bool search(int value);

    // Sort stack in ascending order
    void sort_ascend();

    // Sort stack in descending order
    void sort_descend();
};

