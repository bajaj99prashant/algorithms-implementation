#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* frt;
Node* rear;

void enqueue(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (rear == NULL){
		rear = temp;
		frt = temp;
	}else {
		rear->next = temp;
		rear = temp;
	}
}

void dequeue() {
	if (frt == NULL && rear == NULL){
		return;
	}else if (frt == rear){
		Node* temp = frt;
		rear = NULL;
		frt = NULL;
		delete temp;
	}else {
		Node* temp = frt;
		frt = frt->next;
		delete temp;
	}
}

void front() {
	if (frt == NULL){
		return;
	}else {
		cout << frt->data << " ";
	}
}

int main () {
	frt = NULL;
	rear = NULL;
	enqueue(5);
	enqueue(4);
	enqueue(3);
	enqueue(2);
	enqueue(1);
	dequeue();
	dequeue();
	dequeue();
	front();
	enqueue(6);
	dequeue();
	dequeue();
	front();
	return 0;
}

// memory is a greater problem in queue implementation.
//  if the queue gets full we while implementing an arry version
// we need to make another array of more size thus overall increasing
// time and space complexity, therefore we need to define the implemen
// -tation in linked list.

// main worry of linked list is dequeue
// we can use a trick that we insert at tail end and we dequeue at
// head node, this process can be used to optimize the process

// to optimize the queue implementation we can make a pointer tail
// head which to keep a check of rear node.
// implementing queue this way solves the problem of time complexity 
// but space complexity becomes now a bigger issue
