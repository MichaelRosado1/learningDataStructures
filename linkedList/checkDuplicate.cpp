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


int main() {
	
}
