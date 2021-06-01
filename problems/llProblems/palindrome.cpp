/*** Problem: implement a function to check if a linked list is a palindrome ***/
#include <iostream>

class Node{
    public:
        Node* next = NULL;
        int data;

        Node(int data) {
            this->data = data;
        }

        int getLength() {
            return length_; 
        }

    private:
        int length_;

        Node* head_;
        Node* tail_;

};
