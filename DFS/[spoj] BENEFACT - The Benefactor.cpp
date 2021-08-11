// Problem: BENEFACT - The Benefactor
// Link: https://www.spoj.com/problems/BENEFACT/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 50050

typedef struct Road {
	int length;
	int place;
}Road;

vector<Road> city[MAX];
bool seen[50010];
int path[50010];

int dfs(int n, int source) {
	stack<int> q;
	seen[source] = 1;
	path[source] = 0;
	q.push(source);
	while (!q.empty()) {
		int p = q.top();
		q.pop();
		for (vector<Road>::iterator it = city[p].begin(); it != city[p].end(); it++) {
			int c = (*it).place;
			if (seen[c] == true)
				continue;
			int t = path[p] + (*it).length;
			if (t > path[c]){
				path[c] = t;
			}
			seen[c] = 1;
			q.push(c);
		}
	}
	int max = 0;
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (path[i] > max) {
			temp = i;
			max = path[i];
		}
	}
	return temp;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			path[i] = 0;
			seen[i] = false;
			city[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			Road r1;
			r1.length = c;
			r1.place = b;
			city[a].push_back(r1);
			Road r2;
			r2.length = c;
			r2.place = a;
			city[b].push_back(r2);
		}
		int res = dfs(n, 1);
		for (int i = 1; i <= n; i++) {
			seen[i] = false;
			path[i] = 0;
		}
		res = dfs(n, res);
		cout << path[res] << endl;
	}
	return 0;
}