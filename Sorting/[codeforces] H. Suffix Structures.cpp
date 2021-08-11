// Problem: H - Suffix Structures
// Link: https://codeforces.com/problemset/problem/448/B
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

bool array(string s, string t){
	string _s = s, _t = t;
	sort(_s.begin(), _s.end());
	sort(_t.begin(), _t.end());
	if (_s == _t){
		//cout << "array" << endl;
		return true;
	}
	else{
		return false;
	}
}

bool automaton(string s, string t){
	string temp = "";
	int j = 0;
	for (int i = 0; i< s.length(); i++){
		if (j == t.length()){
			break;
		}
		if (s[i] == t[j]){
			temp += s[i];
			j++;
		}
	}
	if (temp == t){
		//cout << "automaton" << endl;
		return true;
	}
	else{
		return false;
	}
}

bool both(string s, string t){
	for (int i = 0; i < t.length(); i++)
	{
		int p = s.find(t[i]);
		if (p == -1) return false;
		s[p] = '0';
	}
	return true;
}

int main(){
	string s, t;
	cin >> s;
	cin >> t;
	if (array(s, t)) cout << "array" << endl;
	else if (automaton(s, t)) cout << "automaton" << endl;
	else if (both(s, t)) cout << "both" << endl;
	else cout << "need tree" << endl;

	return 0;
}