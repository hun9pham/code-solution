// Problem: MMASS - Mass of Molecule
// Link: https://www.spoj.com/problems/MMASS/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	stack<int> st;
	int x;
	int mass = 0;
	cin >> s; //COOH  CH(CO2H)3  ((CH)2(OH2H)(C(H))O)3
	for (int i = 0; i < s.length(); i++){
		char c = s[i];
		switch (c)
		{
		case '(':
			st.push(c);
			break;
		case 'O':
			st.push(16);
			break;
		case 'H':
			st.push(1);
			break;
		case 'C':
			st.push(12);
			break;
		case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			x = st.top();
			st.pop();
			st.push(x * (c - '0'));
			break;
		case ')':
			int temp = 0;
			while (st.top() != '('){
				temp += st.top();
				st.pop();
			}
			st.pop();
			st.push(temp);
			break;
		}
	}
	while (!st.empty()){
		mass += st.top();
		st.pop();
	}
	cout << mass << endl;

	return 0;
}