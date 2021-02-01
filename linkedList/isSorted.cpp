#include <iostream>

struct Node {
	int data;
	struct Node *nextNode;

}* first = NULL, *second = NULL, *third = NULL;

void display(struct Node *node) {
	struct Node *begin; 
	for (begin = node; begin != NULL; begin = begin->nextNode) {
		std::cout<<begin->data<<" -> ";
	}
}

void createll(int a[], int n) {
	int i;
	struct Node *temp, *last;
	first = new Node;
	first->data = a[0];
	first->nextNode = NULL;
	last = first;

	for (i = 1; i < n; i++) {
		temp = new Node;
		temp->data = a[i];
		temp->nextNode = NULL;
		last->nextNode = temp;
		last = temp;
	}
}

bool isSorted(struct Node *node) {
	int toCompare;
	while (node != NULL) {
		toCompare = first->data;
		if (node->data < toCompare) {
			return false;
		} 
		toCompare = node->data;
		node = node->nextNode;
	}

	return true;
}


int main() {
	int a[] = {1,2,3,4,5};
	createll(a, 5);
	std::cout<<"is the linked list sorted? "<<isSorted(first);
}
