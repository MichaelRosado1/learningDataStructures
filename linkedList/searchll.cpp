#include <iostream>

struct Node {
	int data;
	int *nextNode;
} *first;

void arrToll(int a[], int length) {
	struct Node *temp,*last;
	last = new Node;
	first = new Node;
	first->data = a[0];
	first->nextNode = NULL;
	last = first;

	for (int i = 1; i < length; i++) {
		temp = new Node;
		temp->data = a[i];
		temp->nextNode = NULL;
		last->nextNode = temp;
		last = temp;
	}
}

int main() {
	int x = 10;
	int a[] = {1,2,19,10,20};
	arrToll(a, 5);
}
