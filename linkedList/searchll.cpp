#include <iostream>

struct Node {
	int data;
	struct Node *nextNode;
} *first;

void arrToll(int a[], int length) {
	struct Node *temp,*last;
	first = new Node;
	first->data = a[0];
	last = first;

	for (int i = 1; i < length; i++) {
		temp = new Node;
		temp->data = a[i];
		temp->nextNode = NULL;
		last->nextNode = temp;
		last = temp;
	}
}

struct Node *improvedSerach(struct Node *node, int key) {
	struct Node *q;
	while (node != NULL) {
		if (key == node->data) {
			q->nextNode = node->nextNode;
			node->nextNode = first;
			first = node;
			return node;	
		}
		q = node;
		node = node->nextNode;
	}
	return NULL;
}

void findNum(int x) {
	int position = 0;
	for (struct Node *begin = first; begin != NULL; begin = begin->nextNode) {
		if (x == begin->data) {
			std::cout<<x<<" has been found at position "<<position;
			return;
		} else {
			position++;
			continue;
		}	
	}
	std::cout<<x<<" was not found in the linked list";
}

int main() {
	int x = 10;
	int a[] = {1,2,19,10,20};
	arrToll(a, 5);
}
