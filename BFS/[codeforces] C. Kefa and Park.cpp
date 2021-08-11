// Problem: C. Kefa and Park
// Link: https://codeforces.com/problemset/problem/580/C
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 101000

typedef struct PATH{
	int cat = 0;
	bool visited = false;
	//int numOfCat = 0;
};
int level[MAX];
vector <PATH> path(MAX);
vector<int> tree[MAX];
vector <PATH> temp(MAX);

int BFS_FUNC(int root, vector<int> tree[], int m, int n){
	temp = path;
	int cnt = 0;
	queue<int> q;
	vector<int>restaurant;
	q.push(root);
	path[root].visited = true;
	while (!q.empty()){
		int t = q.front();
		q.pop();
		if (tree[t].size() == 1 && path[tree[t][0]].visited == true && path[t].cat <= m){
			cnt++;
		}
		else{
			for (int i = 0; i < tree[t].size(); i++){
				int c = tree[t][i];
				if (path[c].visited == false){
					q.push(c);
					path[c].visited = true;
					if (path[c].cat == 1)
						path[c].cat = path[t].cat + 1;
					else if (path[t].cat > m)
						path[c].cat = path[t].cat;
				}
			}
		}
	}
	return cnt;
}

int main()
{
	int n; //the number of vertices of the tree
	int m; //the maximum number of consecutive vertices with cats that is still ok for Kefa.
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a; //1 1 0 0
		path[i].cat = a;
	}
	for (int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	cout << BFS_FUNC(1, tree, m, n) << endl;
	return 0;
}