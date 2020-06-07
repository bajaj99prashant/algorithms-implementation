#include <iostream>
#include <string.h>
#include <stack> // stack from standard template library
using namespace std;

void reverse (char c[], int n){
	stack <char> s;
	for (int i=0; i< n; i++){
		s.push(c[i]);
	}
	
	for (int i = 0; i<n; i++){
		c[i] = s.top();
		s.pop();
	}
}

int main (){
	char str[51];
	cout << "enter the string:: " << '\n';
	cin.getline(str, 51);
	reverse(str, strlen(str));
	cout << "output:: " << str;
	return 0;
}


// stack provides us with the neat and intuitive solution
