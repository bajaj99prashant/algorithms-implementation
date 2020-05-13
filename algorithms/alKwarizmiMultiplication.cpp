#include<iostream>
using namespace std;

int mulRes (int x, int y){
	if (y > 0){
		int k;
		k = mulRes(2*x, y/2);
		if (y%2 == 0){
			return k;
		}else {
			return x + k;
		}
	}else {
		return 0;
	}
}

int main () {
	int x, y, result;
	cout << "enter the two numbers for multiplication ";
	cin >> x >> y;
	result = mulRes(x, y);
	cout << "\n" << result;
	return 0;
}
