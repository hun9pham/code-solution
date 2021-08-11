// Problem: 12100 - Printer Queue
// Link: https://vjudge.net/problem/UVA-12100
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>

using namespace std;

typedef struct Job{
	int priority;
	int order;
}Job;

bool cmp(int a, int b){
	return a > b;
}

int main() {
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		vector<int> v;
		queue<Job> q;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			Job j = { x, i };
			v.push_back(x);
			q.push(j);
		}
		sort(v.begin(), v.end(), cmp);
		int k = 0;
		int time = 0;
		while (!q.empty()){
			int pr = q.front().priority;
			int ord = q.front().order;
			q.pop();
			if (pr == v[k]){
				time++;
				if (ord == m) break;
				k++;
			}
			else{
				Job j = { pr, ord };
				q.push(j);
			}
		}
		cout << time << endl;
	}
	return 0;
}