#include <iostream>

struct Node {
	int data;
	Node* nextNode;	
}*first;

void createll(int a[], int n) {
	int i;
	struct Node *t, *last;
	first = new Node;
	first->data = a[0];
	first->nextNode = NULL;
	last = first;

	for (i = 1; i < n; i++) {
		t = new Node;
		t->data = a[i];
		t->nextNode = NULL;
		last->nextNode = t;
		last = t;
	}
}

void findMax(struct Node* node) {
	int max = node->data;
	while (node != NULL) {
		if (node->data > max) {
			max = node->data;
		}
		node = node->nextNode;
	}
	std::cout<<"max is: "<<max;
}

int main() {

	int a[] = {1,2,33,4,21};
	createll(a,5);
	findMax(first);
}
