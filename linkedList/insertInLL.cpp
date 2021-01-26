#include <iostream>

struct Node {
	int data;
	struct Node *nextNode;
} *first;

void createLL(int a[], int n) {
	struct Node *t, *last;
	first = new Node;
	first->data = a[0];
	last = first;

	for (int i = 0; i < n; i++) {
		t = new Node;
		t->data = a[i];
		t->nextNode = NULL;
		last->nextNode = t;
		last = t;
	}
}

int main() {
	int a[] = {3,4,7,19,20,8,33,2};
	createLL(a, 8);
}
