#include <iostream>
#define maxSize 101
using namespace std;

int arr[maxSize];
int top = -1;

void push (int data){
	if (top == maxSize - 1){
		cout << "\nstack overflow";
		return;
	}
	top = top + 1;
	arr[top] = data;
}

void print() {
	int t = top;
	while (t >= 0){
		cout << arr[t] << " ";
		t--;
	}
}

void pop (){
	if (top == -1){
		cout << "no element to pop\n";
	}
	top = top - 1;
}

int main () {
	pop();
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	print();
	cout << "\n";
	pop();
	print();
	return 0;
}
