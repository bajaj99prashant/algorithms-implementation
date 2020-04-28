#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* link;
};

Node* head;// global variable that can be accessed anywhere

// inserting a node at the end
void insertEnd(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;
	Node* temp1 = head;// when we declare temp1 like this it takes the instance of the head and any modification in temp1 is also a modification in head without changing what head points to
	while (temp1->link != NULL){
		temp1 = temp1->link;
	}
	temp1->link = temp;
}

// inserting node at particular position
void insertNth(int x, int pos){
	Node* temp = new Node();
	temp->data = x;
	temp->link = NULL;
	if (pos == 1){
		temp->link = head;
		head = temp;
		return;
	}
	Node* temp1 = head;
	for (int i = 0; i<pos-2; i++){
		temp1 = temp1->link;
	}
	temp->link = temp1->link;
	temp1->link = temp;
	
}

// inserting node at the begining of the list
void insertBegin(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->link = head;
	head = temp;
}

// delete a node at nth position
void deleteNode(int pos){
	Node* temp = head;
	if (pos == 1){
		head = temp->link;// head now points to second node
		delete temp;
		return;
	}
	for (int i = 0; i<pos-2; i++){
		temp = temp->link;
	}
	// temp points to (n - 1)th node
	Node* temp1 = temp->link;// nth node
	temp->link = temp1->link;// fixed the link part of the linked list
	delete temp1;// deletes the unrequired nth linking part from the heap frame
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

// main function
int main()
{
	head = NULL;// creating empty list
	insertBegin(2);
	insertBegin(3);
	insertBegin(4);
	insertBegin(5);
	insertBegin(6);// list is 6, 5, 4, 3, 2
	print();
	int n;
	cout << "position at which the node in linked list is to be deleted:\n";
	cin >> n;
	deleteNode(n);
	print();
}




/*
    concept of linked list 
    the only information we have of linked list is the address to which head of the linked list points

    struct Node {
        int data;
        Node* nextNode;
    };
    address of the head node gives us access to the complete list
    the main drawback of linked list is that we cannot read any element in constant amount of time
    insertion also takes place in big-Oh of n
    deletion also takes place in big-Oh of n
    only advantage linked list provides is that it is dynamic and can be increased and decreased in the size
 */
