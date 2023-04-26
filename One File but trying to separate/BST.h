#pragma once
#include "Datastructure.h"
#include "BSTNode.h"
class BST :public Datastructure {
private:
    BSTNode* root;
    string Dstype;
public:
    BST();

    string gettype();

    BSTNode* BSTgetRoot();

    BSTNode* insert(BSTNode* node, int value);

    void BSTaddItem(int value);

    //only used internally by the delete item method
    BSTNode* deleteNode(BSTNode* node, int value);

    void BSTdeleteItem(int value);

    BSTNode* minValueNode(BSTNode* node);

    void BSTinorder(BSTNode* node);

    void BSTpostorder(BSTNode* node);

    void BSTpreorder(BSTNode* node);

    void print();

    void sort_ascend();
    void sort_descend();


    BST(const BST& other);


    BSTNode* copyTree(BSTNode* node);


    bool search(int value);

    ~BST();
    BSTNode* deleteTree(BSTNode* node);

};


