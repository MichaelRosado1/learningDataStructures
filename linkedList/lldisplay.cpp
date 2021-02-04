#include <iostream>

struct Node {
	//data contained in the current node
	int data;
	//a pointer to the next node in the list
	struct Node* nextNode;
//first is a glabal variable
}*first = NULL;

void createll(int a[], int n) {
	//indexing variable
	int i;

	//creates
	struct Node *t, *last;
	first = new Node;
	//sets the first node to be equal to the first element in the array 
	first->data = a[0];
	//since the list only contains one element right now,
	//we set the last node equal to the first node
	last = first;
	
	//iterate through the length of the array 
	for (i = 1; i < n; i++) {
		//create a new node
		t = new Node;
		
		//set the node's data equal to the ith element in the array
		t->data = a[i];
		
		//next node is null since we haven't declared it yet
		t->nextNode = NULL;

		//update the last variable since the last element in the list is
		//now equal to the next list item
		last->nextNode=t;
		last = t;
	}
		
}

void Display(struct Node *p) {
	while (p != NULL) {
		std::cout<<p->data<<" -> ";
		p=p->nextNode;
	}
	std::cout<<"NULL";
}

int count(struct Node  *node) {
	int count = 0;
	while (node != NULL) {
		count++;
		node = node->nextNode;
	}

	return count;
}

void insert(struct Node *node, int index, int data) {
	struct Node *temp;
	if (index < 0 || index > count(node)) {
		return;
	}

	temp = new Node;
	temp->data = data;

	if (index == 0) {
		temp->nextNode = first;
		first = temp;
	} else {
		for (int i = 0; i < index - 1; i++) {
			node = node->nextNode;
		}
		temp->nextNode = node->nextNode;
		node->nextNode = temp;
	}

}

int main() {
	int a[] = {3,5,6,7,15};
	
	createll(a,5);

	insert(first, 0, 10);

	Display(first);

}
