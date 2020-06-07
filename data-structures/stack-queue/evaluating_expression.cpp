#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int compo(int a, int b, char c){
	if (c == '/'){
		return a/b;
	}
	else if (c == '*'){
		return a*b;
	}
	else if (c == '-'){
		return a-b;
	}
	else {
		return a+b;
	}
}

int eval(char ar[], int n){
	stack <int> s;
	for (int i = 0; i < n; i++){
		int ch = ar[i];
		if (isdigit(ch)){
			int a = ch - '0';
			s.push(a);
		}else {
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			int re;
			re = compo(op1, op2, ch);
			s.push(re);
		}
	}
	return s.top();
}

int main () {
	char arr[50];
	cout << "enter the expression:: ";
	cin.getline(arr, 50);
	cout << eval(arr, strlen(arr));
	return 0;
}

// postfix expression
// postfix is easy because we can parse the string from left to right.
