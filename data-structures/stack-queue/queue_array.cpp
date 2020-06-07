#include <iostream>
using namespace std;

int a[50];
int front = -1;
int rear = -1;

bool isEmpty(){
	if (front == -1 && rear == -1){
		return true;
	}else {
		return false;
	}
}

void enqueue (int x){
	if (front == (rear + 1)%50){
		return;
	}else if (isEmpty()){
		rear += 1;
		front += 1;
		a[rear] = x;
	}else {
		rear = (rear + 1)%50;
		a[rear] = x;
	}
}

void dequeue () {
	if (isEmpty()){
		return;
	}else if (front == rear){
		front = -1;
		rear = -1;
	}else {
		front = (front + 1)%50;
	}
}

int main () {
	return 0;
}


// a queue can be defined as the list with restriction that insertion can be 
// performed at one end and deletion can be performed from other end.

// queue operations 
// 1. enqueue
// 2. dequeue
// 3. front or peek
// 4. isempty
// 5. isfull

// we use queue whenever there is a possibility of the shared resource.
// queue can be helpful in simulating weight

// in queue we look in logical way of array to be a circular array
// in circular array when the end of the array is met we fetch 0th index of the array.
// it is somewhat like modular airthmetic, when the a cycle completes it returns back.	
// if current pos is i, we can say next pos = (i + 1) mod N
// and prev pos = (i + N - 1) mod N
