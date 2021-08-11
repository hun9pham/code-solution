// Problem: Queue using Two Stacks
// Link: https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	stack<int> s1;
	stack<int> s2;
	int n;
	cin >> n;
	while (n-- > 0){
		int s;
		int x;
		cin >> s;
		if (s == 1){
			cin >> x;
			s1.push(x);
		}
		else{
			if (s2.empty()){
				while (!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}
			if (s == 2){
				s2.pop();
			}
			else if (s == 3){
				cout << s2.top() << endl;
			}
		}
	}
	return 0;
}