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

int main() {
	int a[] = {3,5,6,7,15};
	
	createll(a,5);

	Display(first);

}
