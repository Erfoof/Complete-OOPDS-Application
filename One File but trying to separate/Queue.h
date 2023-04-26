#pragma once
#include "Datastructure.h"
class Queue : public Datastructure {
public:
    Queue(); // default constructor

    string gettype();

    // copy constructor
    Queue(const Queue& other);

    // assignment operator
    Queue& operator=(const Queue& other) {
        data = vector<int>(other.data);
        return *this;
    }


    // destructor
    ~Queue() {
        data.clear();
    }
    // print queue
    void print();

    // search queue
    bool search(int value);

    // sort queue in ascending
    void sort_ascend();
    // sort queue in ascending
    void sort_descend();

    // push (add item)
    void Queuepush(int value);

    // pop (pop item)
    void Queuepop();

    // front (return front of queue)
    int Queuefront();

    // back (return back of queue)
    int Queueback();

    // isFull (return a bool value)
    bool QueueisFull();

    // isEmpty (return a bool value)
    bool QueueisEmpty();

private:
    vector<int> data;
    string Dstype;
};


