// Problem: A. Vitaly and Strings
// Link: https://codeforces.com/problemset/problem/518/A
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
	string s, t;
	cin >> s >> t;
	int len = s.length();
	string obj = s;

	for (int i = len - 1; i >= 0; i--){
		if (obj[i] == 'z'){
			obj[i] = 'a';
		}
		else{
			obj[i] = obj[i] + 1;
			break;
		}
	}
	if (t > obj){
		cout << obj << endl;
	}
	else{
		cout << "No such string" << endl;
	}

	return 0;
}