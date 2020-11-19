#include <iostream>
#include <bits/stdc++.h>
//first in first out
//  ->stacks are first in last out
#define MAX 10
using namespace std;
struct Queue {
    int front, back;
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
}

int main() {

}

