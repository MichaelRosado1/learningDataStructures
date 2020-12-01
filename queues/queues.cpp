#include <iostream>
//first in first out
//  ->stacks are first in last out
#define MAX 10
using namespace std;
struct Queue {
    int front, back;
    int size;
    int queue[MAX];
    Queue() {
       front = back = -1; 
    }
    bool isFull() {
        // if the queue reaches from the front to the back, it is full
        if (front == 0 && back == MAX - 1) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }
    void enqueue(int value) {
        if (this->isFull()) {
            return;
        }
        this->back = (this->back + 1) % MAX;
        this->queue[this->back] = value;
        this->size += 1;
    }
    
};
//adding this to make sure commit works in github
int main() {
    
}

