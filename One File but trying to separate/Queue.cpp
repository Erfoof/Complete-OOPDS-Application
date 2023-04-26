#include "Queue.h"
//----------------------------queue;
//Constructor
Queue::Queue() {
    Dstype = "queue";
};

string Queue::gettype() {
    return Dstype;
};


//copy constructor
Queue :: Queue(const Queue& other) {
    data = vector<int>(other.data);
}


// print queue
void Queue::print() {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
}

// search queue
bool Queue::search(int value) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

// sort queue in ascending
void Queue::sort_ascend() {
    sort(data.begin(), data.end());
}
// sort queue in ascending
void Queue::sort_descend() {
    sort(data.rbegin(), data.rend());
}   

// push (add item)
void Queue::Queuepush(int item) {
    data.push_back(item);
}

// pop (pop item)
void Queue::Queuepop() {
    if (!data.empty()) {
        data.erase(data.begin());
    }
}

// front (return front of queue)
int Queue::Queuefront() {
    if (!data.empty()) {
        return data.front();
    }
    return -1;
}

// back (return back of queue)
int Queue::Queueback() {
    if (!data.empty()) {
        return data.back();
    }
    return -1;
}

// isFull (return a bool value)
bool Queue::QueueisFull() {
    return false; // queues can dynamically resize, so it can never be full
}

// isEmpty (return a bool value)
bool Queue::QueueisEmpty() {
    return data.empty();
}
