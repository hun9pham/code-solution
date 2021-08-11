// Problem: CAM5 - prayatna PR
// Link: https://www.spoj.com/problems/CAM5/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 100000
typedef long long int ll;

bool seen[MAX_N];
vector<int> person[MAX_N];
int path[MAX_N];

void dfs(int root){
	stack<int>s;
	s.push(root);
	seen[root] = true;
	while (!s.empty()){
		int t = s.top();
		s.pop();
		if (person[t].size() > 0){
			for (int i = 0; i < person[t].size(); i++){
				if (seen[person[t][i]] == false){
					s.push(person[t][i]);
					path[person[t][i]] = t;
					seen[person[t][i]] = true;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t-- > 0){
		int N;
		cin >> N;
		for (int i = 0; i < N; i++){
			seen[i] = false;
			person[i].clear();
			path[i] = -1;
		}
		int e;
		cin >> e;
		for (int i = 0; i < e; i++){
			int a, b;
			cin >> a >> b;
			person[a].push_back(b);
			person[b].push_back(a);
		}
		for (int i = 0; i < N; i++){
			if (seen[i] == false){
				dfs(i);
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++){

			if (path[i] == -1){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}