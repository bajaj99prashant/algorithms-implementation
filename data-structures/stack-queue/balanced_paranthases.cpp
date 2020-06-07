#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool checkparanthases(char exp[], int n){
	stack<char> s;
	for (int i = 0; i < n; i++){
		int ch = exp[i];
		if (ch == '(' || ch == '{' || ch == '['){
			s.push(ch);
		}else {
			if(ch == ')' || ch == '}' || ch == ']'){
				if (s.empty()){
					return false;
				}else {
					if ((s.top() == '(' && ch == ')') || (s.top() == '{' && ch == '}') || (s.top() == '[' && ch == ']')){
						s.pop();
					}else {
						return false;
					}
				}
			} 
		}
	}
	
	return (s.empty()) ? true : false;
}

int main () {
	char exp[50];
	int result;
	cout << "enter the expression ";
	cin.getline(exp, 50);
	result = checkparanthases(exp, strlen(exp));
	cout << result;
	return 0;
}


// last opened should be claosed first
// should have equal no of opening and closing paranthases
// opening paranthases must be on left and closing paranthases must be on right
