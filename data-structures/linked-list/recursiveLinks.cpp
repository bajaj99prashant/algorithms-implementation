#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* link;
};
Node* head;
void print (Node* p){
	if (p == NULL) return;// exit condition
	cout << p->data << " "; //to print in correct order
	print (p->link);
	//cout << p->data << " ";  to print in reverse order
}

// reversing a linked list using recursion and not just printing
void reverseRecursive (Node* p){
	if (p->link == NULL){
		head = p;
		return;
	}
	reverseRecursive(p->link);
	Node* q = p->link;
	q->link = p;
	p->link = NULL;
}

void insert(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;
	Node* temp1 = head;
	if (head == NULL){
		head = temp;
	}else {
		while (temp1->link != NULL){
			temp1 = temp1->link;
		}
		temp1->link = temp;
	}
}

int main (){
	head = NULL; //local variable
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	reverseRecursive(head);
	print(head);
	return 0;
}

// using concepts of recursion to print and traverse the linked list

// in the print funciton when the recursive call is finished and than we 
// cout an statement then order of printing reverses.

// all local variable sit in the stack frame of the function
// all the dynamic memory sits in the heap frame of the function

// keep in mind that the sequence of operations in recursion is very important
// i.e what is happening before and after the recursive calls

// in recursion we save the execution of all the function calls in the stack 
// section of the memory.
