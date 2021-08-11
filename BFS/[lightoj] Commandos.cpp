// Problem: Commandos
// Link: https://lightoj.com/problem/commandos
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 150
#define INF 1e9
typedef pair<int, int> pii;
typedef long long int lli;

int n, r;
int u, v;
int d, s;
vector<int> buildings[MAX];
bool seen[MAX];
int distSrc[MAX];
int distDes[MAX];

void bfs(int src, int dist[]){
	memset(seen, false, sizeof(seen));
	queue<int> q;
	q.push(src);
	seen[src] = true;
	dist[src] = 0;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (auto it : buildings[u]){
			if (seen[it] == false){
				seen[it] = true;
				dist[it] = dist[u] + 1;
				q.push(it);
			}
		}
	}
}

int main() {
	static int tc = 1;
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		cin >> r;
		memset(distSrc, 0, sizeof(distSrc));
		memset(distDes, 0, sizeof(distDes));
		for (int i = 0; i < n; i++){
			buildings[i].clear();
		}

		for (int i = 0; i < r; i++){
			int u, v;
			cin >> u >> v;
			buildings[u].push_back(v);
			buildings[v].push_back(u);
		}
		cin >> s >> d;
		bfs(s, distSrc);
		bfs(d, distDes);
		int res = 0;
		for (int i = 0; i < n; i++){
			res = max(res, distSrc[i] + distDes[i]);
		}
		printf("Case %d: %d\n", tc++, res);
	}

	return 0;
}