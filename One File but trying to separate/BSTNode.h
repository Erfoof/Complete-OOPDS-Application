#pragma once
class BSTNode { //can either be a struct inside of the class BST or a separate class. This way is more reliable.
public:
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
