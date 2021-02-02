#include <iostream>
struct Node {
	int data;
	Node *nextNode;
} *first;

void createll(int a[], int n) {
	int i;

	struct Node *t, *last;
	first = new Node;
	first->data = a[0];
	last = first;
	for (i = 1; i < n; i++) {
		t = new Node;		
		t->data = a[i];
		t->nextNode = NULL;
		last->nextNode = t;
		last = t;
	}
}

void RemoveDuplicate(struct Node *node) {
	struct Node *q = node->nextNode;

	while (q != NULL) {
		if (node->data != q->data) {
			node = q;
			q = q->nextNode;	
		} else {
			node->nextNode = q->nextNode;
			q = node->nextNode;
		}
	}
}

void display(struct Node *node) {
	while (node != NULL) {
		std::cout<<node->data<< " -> ";
		node = node->nextNode;
	}
}

int main() {
	int a[] = {1,2,3,4,4,5};
	createll(a, 6);	
	RemoveDuplicate(first);

	display(first);

}
