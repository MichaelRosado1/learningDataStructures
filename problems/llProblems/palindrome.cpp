/*** Problem: implement a function to check if a linked list is a palindrome ***/
#include <iostream>
using namespace std;
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

        void addAtHead(int d) {
            Node* newNode = new Node(d);

            //if head is null, this is the first element in the list
            //its important to remember that the pointers are pointing to nodes, they are not the nodes themselves
            newNode->next = head_;
            //since the newnode->next pointer is set to head, if we set head_ to new node, we will lose no data and the head will now
            //be in the correct position
            head_ = newNode;
            length_++;
        }

        //in order to find if we have a palindrome, all we need to do is reverse the list and compare the first half of list
        //if they are equal, then it is a palindrome
        void reverse() {
            Node* currentNode = head_;
            Node* previousNode = NULL;

            while (currentNode) {
                Node* temp = currentNode->next;
                currentNode->next = previousNode;
                previousNode = currentNode;
                currentNode = temp;
            }
            head_ = previousNode;
        }

        void print() {
            Node* currentNode = head_;

            while (currentNode) {
                cout<<currentNode->data<<" -> ";                
                currentNode = currentNode->next;
            }
        }

    private:
        int length_;

        Node* head_;
        Node* tail_;

};


int main() {
    Node* node = new Node(1);
    node->addAtHead(10);
    node->addAtHead(20);
    node->print();
}
