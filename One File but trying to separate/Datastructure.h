#pragma once
#include "BSTNode.h"
#include "DLLNode.h"
#include "SLLNode.h"
#include <iostream> 
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Datastructure {
public:
    //BST Methods;
    virtual BSTNode* BSTgetRoot() {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };
    virtual void BSTdeleteItem(int value) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void BSTaddItem(int value) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void BSTinorder(BSTNode* node) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void BSTpostorder(BSTNode* node) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void BSTpreorder(BSTNode* node) {
        cout << "This datastructure does not support the method called" << endl;
    };
    // ALl methods have;
    virtual void print() = 0;

    virtual void sort_ascend() {
    };

    virtual void sort_descend() {
    };

    virtual bool search(int value) {
        return true;;
    };



    virtual string gettype() = 0;

    //DLL Methods;
    virtual void DLLaddNodeToEnd(int data) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void DLLdeleteNodeFromEnd() {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void DLLaddNodeToFront(int data) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void DLLdeleteNodeFromFront() {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void DLLinsertAfter(int data, int value) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual DLLNode* DLLpointToBeginning() {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };

    virtual DLLNode* DLLpointToEnd() {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };

    virtual int DLLgetValueAtPointer(DLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    virtual DLLNode* DLLmovePointerForward(DLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };

    virtual DLLNode* DLLmovePointerBackward(DLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };

    virtual bool DLLatEndOfList(DLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return true;
    };

    virtual bool DLLatHeadOfList(DLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return true;
    };

    //SLL Methods;


    virtual void SLLaddNodeToEnd(int data) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual  void SLLdeleteNodeFromEnd() {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void SLLaddNodeToFront(int data) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void SLLdeleteNodeFromFront() {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual void SLLinsertAfter(int data, int value) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual SLLNode* SLLpointToBeginning() {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };

    virtual SLLNode* SLLpointToEnd() {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };

    virtual int SLLgetValueAtPointer(SLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    virtual SLLNode* SLLmovePointerForward(SLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return nullptr;
    };

    virtual bool SLLatEndOfList(SLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };


    virtual bool SLLatHeadOfList(SLLNode* pointer) {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    //stack methods;

    virtual void Stackpush(int item) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual  void Stackpop() {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual int Stacktop() {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };
    virtual  bool StackisFull() {
        cout << "This datastructure does not support the method called" << endl;
        return false;
    };

    virtual bool StackisEmpty() {
        cout << "This datastructure does not support the method called" << endl;
        return false;
    };



    //Queue methods;


    virtual void Queuepush(int value) {
        cout << "This datastructure does not support the method called" << endl;

    };

    virtual void Queuepop() {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual int Queuefront() {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    virtual int Queueback() {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    virtual  bool QueueisFull() {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    virtual bool QueueisEmpty() {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    //Variable methods;

    virtual void VarAssign(int value) {
        cout << "This datastructure does not support the method called" << endl;
    };

    virtual int Vargetvalue() {
        cout << "This datastructure does not support the method called" << endl;
        return 0;
    };

    virtual void VarIfTrue(bool condition, string message) {
        cout << "This datastructure does not support the method called" << endl;
    };
    virtual void VarIfFalse(bool condition, string message) {
        cout << "This datastructure does not support the method called" << endl;
    };

};


