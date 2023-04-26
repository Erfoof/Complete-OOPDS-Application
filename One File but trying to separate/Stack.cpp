#include "Stack.h"
#include <iostream>
using namespace std;
//constructor
Stack::Stack() {
    Dstype = "stack";
};
string Stack::gettype() {
    return Dstype;
};

//copy constructor
Stack::Stack(const Stack& other) {
    for (int i = 0; i < other.arr.size(); i++) {
        arr.push_back(other.arr[i]);
    }
}


// Destructor
Stack :: ~Stack() {
    arr.clear();
}

// Push item
void Stack::Stackpush(int item) {
    arr.push_back(item);
}

// Pop item
void Stack::Stackpop() {
    if (!arr.empty()) {
        arr.pop_back();
    }
}

// Display top of the stack
int Stack::Stacktop() {
    if (!arr.empty()) {
        return arr.back();
    }
    return -1;
}

// Check if stack is full
bool Stack::StackisFull() {
    return false; // vector can dynamically resize, so it can never be full
}

// Check if stack is empty
bool Stack::StackisEmpty() {
    return arr.empty();
}

// Print stack
void Stack::print() {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

// Search stack
bool Stack::search(int value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

// Sort stack in ascending order
void Stack::sort_ascend() {
    sort(arr.begin(), arr.end());
}

// Sort stack in descending order
void Stack::sort_descend() {
    sort(arr.rbegin(), arr.rend());
}
