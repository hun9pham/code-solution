// Problem: Breadth First Search: Shortest Reach
// Link: https://www.hackerrank.com/contests/hackerolympicscodechallenge/challenges/bfsshortreach
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 1010
int level[MAX];

void BFS_FUNC(int root, int n, vector<int> graph[]){
	vector<int> path(MAX, -1);
	vector<bool> visited(MAX, false);
	queue<int> q;
	q.push(root);
	visited[root] = true;
	path[root] = 0;
	while (!q.empty()){
		int t = q.front();
		q.pop();
		for (int i = 0; i < graph[t].size(); i++){
			int c = graph[t][i];
			if (visited[c] == false){
				path[c] = path[t] + 6;
				q.push(c);
				visited[c] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (path[i] != 0)
			cout << path[i] << ' ';
	}
	cout << endl;
}

int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int n, m;
		cin >> n >> m;
		vector<int> graph[MAX];
		for (int j = 0; j < m; j++){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int s;
		cin >> s;
		BFS_FUNC(s, n, graph);
	}
	return 0;
}