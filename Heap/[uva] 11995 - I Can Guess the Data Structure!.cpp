// Problem: I Can Guess the Data Structure!
// Link: https://vjudge.net/problem/HackerRank-find-the-running-median
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n;
	while (cin >> n){
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;
		bool a = true;//stack
		bool b = true;//queue
		bool c = true;//priority queue
		while (n--){
			int t;
			cin >> t;
			switch (t)
			{
			case 1:
				int x;
				cin >> x;
				st.push(x);
				q.push(x);
				pq.push(x);
				break;
			case 2:
				int k;
				cin >> k;
				if (st.empty() || k != st.top()){
					a = false;
				}
				else
					st.pop();
				if (q.empty() || k != q.front()){
					b = false;
				}
				else
					q.pop();
				if (pq.empty() || k != pq.top()){
					c = false;
				}
				else
					pq.pop();
				break;
			}
		}
		//check
		if (a && !b && !c){
			cout << "stack" << endl;
		}
		else if (!a && b && !c){
			cout << "queue" << endl;
		}
		else if (!a && !b && c){
			cout << "priority queue" << endl;
		}
		else if (!a && !b && !c){
			cout << "impossible" << endl;
		}
		else{
			cout << "not sure" << endl;
		}
	}
	return 0;
}