// Problem: ONP - Transform the Expression
// Link: https://www.spoj.com/problems/ONP/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	vector<string> v;
	for (int i = 0; i < n; i++){
		cin >> s;
		v.push_back(s);
	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		int i = 0;
		string o = "";
		stack<char> st;
		while (i < (*it).length()){
			char c = (*it)[i];
			switch (c)
			{
			case '(':
				break;
			case '+': case '-': case '*': case '/': case '^':
				st.push(c);
				break;
			case ')':
				o += st.top();
				st.pop();
				break;
			default:
				o += c;
				break;
			}
			i++;
		}
		cout << o << endl;
	}
	return 0;
}