#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int data;
	Node* link;
};

Node* head;

void reverse(){
	if(head == NULL) return;
	stack<Node*> s;// initializing the stack
	Node* temp = head;
	while (temp != NULL){
		s.push(temp);
		temp = temp->link;
	}
	temp = s.top();
	head = temp;
	s.pop();
	while(!s.empty(){
		temp->link = s.top();
		s.pop();
		temp = temp->link;
	}
	temp->link = NULL;
}

void insert(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;
	Node* temp1 = head;
	while (temp1->link != NULL){
		temp1 = temp1->link;
	}
	temp1->link = temp;
} 

void print(){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->link;
	}
}

int main (){
	head = NULL;
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	print();
	
	return 0;
}


// we cannot use two variables and swap the values at that variables in linked list
// because the linked list is not continuos block of memory.

// using recursion to implement stack we do not use stack explicitely to reverse a 
// linked list but we are using stack implicitely in the form of recursion.
