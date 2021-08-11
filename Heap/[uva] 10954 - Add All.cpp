// Problem: 10954 - Add All
// Link: https://vjudge.net/problem/UVA-10954
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n;
	int a;
	while (1){
		cin >> n;
		priority_queue<int, vector<int>, greater<int> > q;
		if (n == 0) break;
		for (int i = 0; i < n; i++){
			cin >> a;
			q.push(a);
		}
		int cost = 0;
		int total = 0;
		while (!q.empty()){
			int a = q.top();
			q.pop();
			if (q.empty()) break;
			int b = q.top();
			q.pop();
			cost = a + b;
			total += cost;
			q.push(cost);
		}
		cout << total << endl;
	}
	return 0;
}