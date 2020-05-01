#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* link;
};

Node* head;

// reversing the list using iterative method
void reverseIterative() {
	Node* current, prev, next;
	current = head;
	prev = NULL;
	while (current != NULL ){
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

// inserting node at the begining of the list
void insertBegin(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = head;
	head = temp;
}

// printing out the linked list
void print(){
	cout << "elements in the link list ";
	Node* temp = head;
	if (temp == NULL){
		cout << "Linked List is empty \n";
	}else {
		while (temp != NULL){
			cout << temp->data << " ";
			temp = temp->link;
		}
	}
	cout << "\n";
}

int main () {
	head = NULL;
	insertBegin(2);
	insertBegin(3);
	insertBegin(4);
	insertBegin(5);
	insertBegin(6);
	print();// 6, 4, 5, 3, 2
	reverseIterative();
	print();// 2, 3, 4, 5, 6
	return 0;
}

// reversing a linked list means actually changing the links between the
// nodes and not only changing the data in the nodes.

// there are two approaches to solve the problem
// 1. using iterative approach
// 2. using recursive approach

// in iterative approach we iterate over linked list and change the links 
// of nodes each time for particular node.
