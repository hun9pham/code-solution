// Problem: Extended Traffic
// Link: https://lightoj.com/problem/extended-traffic
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define INF 1e9
#define MAX 100055
typedef pair<int, int> pii;

struct Node{
	int src, des, wei;
};

int n, m, q;
Node node[MAX];
int dist[MAX];
int busy[MAX];

void Bellman_Ford(int src){
	for (int i = 0; i <= n; i++){
		dist[i] = INF;
	}
	int u, v, w;
	dist[src] = 0;
	for (int i = 0; i < n - 1; i++){
		for (int i = 1; i <= m; i++){
			u = node[i].src;
			v = node[i].des;
			w = node[i].wei;
			if (dist[u] != INF && dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
			}
		}
	}
}

int main(){
	int t;
	static int test_case = 1;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> busy[i];
		}
		cin >> m;
		for (int i = 1; i <= m; i++){
			cin >> node[i].src >> node[i].des;
			int w = busy[node[i].des] - busy[node[i].src];
			node[i].wei = w*w*w;
		}
		Bellman_Ford(1);
		printf("Case %d:\n", test_case++);
		cin >> q;
		while (q--){
			int num;
			cin >> num;
			if (dist[num] < 3 || dist[num] == INF){
				printf("?\n");
			}
			else printf("%d\n", dist[num]);
		}
	}

	return 0;
}