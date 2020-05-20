#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* link;
};

struct Node* top = NULL;

void push (int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = top;
	top = temp;
}

void pop(){
	Node* temp;
	if (top == NULL){
		return;
	}
	temp = top;
	top = top->link;
	delete temp;
}

void print() {
	Node* temp = top;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->link;
	}
}

int main () {
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);
	print();
	cout << '\n';
	pop();
	print();
	return 0;
}

/*
 * to insert/delete from the end of the linked list it requires O(n) time.
 * to insert/delete at the beginning it requires O(1).
 * what we are doing in the stack is we are pushing a node at the begining of the
   linked list and top works as head of the linked list, so that pushing, popping 
   and fetching should be O(1) time complexity.
 * the advantage of using linked list over array for stack implementation is that
   we don't have to worry for stack overflow because we are using heap section of the 
   memory for making linked list.
 */
