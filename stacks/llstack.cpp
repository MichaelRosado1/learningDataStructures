#include <iostream>

class Node {
	public:
		int data;
		Node *nextNode;
};

class Stack {
	private:
		Node *top;
	public:
		Stack() {
			top = NULL;
		}

		void push(int x);
		int pop();
		void Display();
};

void Stack::push(int x) {
	Node *temp = new Node;
	if (temp == NULL) {
		std::cout<<"stack is full";
	} else {
		temp->data = x;
		temp->nextNode = top;
		top = temp;
	}
}

int Stack::pop() {
	int x = -1;
	if (top == NULL) {
		std::cout<<"stack is empty\n";
	} else {
		x = top->data;
		Node *t = top;
		top = top->nextNode;
		delete t;
	}
	return x;
}

void Stack::Display() {
	Node *node = top;
	while (node != NULL) {
		std::cout<<node->data<<" -> ";
		node = node->nextNode;
	}
	std::cout<<"\n";
}
int main() {
	Stack stack;
	stack.push(10);
	stack.push(11);
	stack.push(12);
	stack.push(13);	
	stack.Display();
	stack.pop();
	stack.Display();
}
