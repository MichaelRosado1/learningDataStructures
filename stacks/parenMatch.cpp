#include <iostream>

class Node {
	public:
		char data;
		Node *nextNode;
};

class Stack {
	public:
		Node *top;
		Stack() {
			top = NULL;
		}
		void push(char x);
		char pop();
		void Display();
};

void Stack::push(char x) {
	Node *t = new Node;
	//if the stack is full
	if (t == NULL) {
		std::cout<<"stack is full";
	} else {
		//set the data in the new node
		t->data = x;
		//set the next node equal to the top node
		t->nextNode = top;
		//moves the top node over and sets the new pushed node to the stack
		top = t;
	}
}

char Stack::pop() {
	int x = -1;
	//if the stack is empty
	if (top == NULL) {
		std::cout<<"stack is empty";
	} else {
		//sets x equal to the top nodes data to prevent mem loss
		x = top->data;
		//new temp node to store the top node
		Node *t = top;
		//sets the top node equal to the next node
		top = top->nextNode;
		//removes data from heap memory 
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


int isBalanced(char *exp) {
	int i;
	Stack stack;
	for (i = 0;exp[i] != '\0'; i++) {
		if (exp[i] == '(') {
			stack.push(exp[i]);
		} else if (exp[i] == ')') {
			if (stack.top == NULL) {
				return 0;

			} else {
				stack.pop();
			}
		}
	}
	if (stack.top == NULL) {
		return 1;
	} else {
		return 0;
	}

}

int main() {
	char *expression ="((a+b) * (c-d))";
	std::cout<<isBalanced(expression)<<" ";	
}
