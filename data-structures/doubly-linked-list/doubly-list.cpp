/* the idea of the doubly linked list is quite simple 
instead of the single link in singly linked list, we have two links
in doubly linked list, one to the next node and one to previous. */

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};
Node* head; // global variable pointer to head node

Node* createNode(int x){
	Node* temp = new Node();// we can create node like struct Node variable but it will be cleared
	// as soon as the function ends therefore we dynamically allocate node using new op.
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertAtHead(int x){
	Node* temp = createNode(x);
	if (head == NULL){
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
	
}

void print() {
	Node* temp = head;
	cout << "forward ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void reversePrint(){
	Node* temp = head;
	if (temp == NULL) return;
	
	while (temp->next != NULL){
		temp = temp->next;
	}
	
	cout << "reverse ";
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << "\n";
} 

int main (){
	head = NULL;
	insertAtHead(2);
	insertAtHead(3);
	insertAtHead(4);
	insertAtHead(5);
	insertAtHead(6);
	print();
	reversePrint();
	return 0;
}

/*
 the main issue of the doubly linked list is the memory, one node takes 12 
 bytes of memory, every pointer and integer takes 32bits of memory.
 suppose there are 10 nodes in doubly linked list it would take 120 bytes of 
 memory. 
 the use of doubly link list is great in the sense we can move in whole list only from one node.
  */

/*
 * we cannot access something directly from heap using a name, a pointer is 
   always required to access something from the heap.
 * therefore a concept of pointer is very much useful in the language like c and c++,
   because of the way memory and execution of a function works in c++.
 */
