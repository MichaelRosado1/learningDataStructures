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

int count(struct Node *p) {
	struct Node *begin = new Node;
	int count = 1;
	for (begin = p; begin != NULL; begin = begin->nextNode) {
		count++;	
	}

	return count;
}
void insert(struct Node *p, int index, int x) {
	//not a valid position in the list
	if (index < 0 || index > count(p)) {
		return;
	}
	struct Node *t = new Node; 
	t->data = x;	
	
	//if the index is the first position 
	if (index == 0) {
		//we have to switch the original first node with the new node, t
		t->nextNode = first;
		first = t;
	} else {
		//loop through the entire linked list
		for (int i = 0; i < index - 1; i++) 
			p = p->nextNode;
		t->nextNode = p->nextNode;
		p->nextNode = t;
	}	



}

int main() {
	int a[] = {3,5,7};
	createLL(a, 3);
	insert(first,3,15);

	while (first != NULL) {
		std::cout<<first->data<<" ->";
		first = first->nextNode;
	}



}
