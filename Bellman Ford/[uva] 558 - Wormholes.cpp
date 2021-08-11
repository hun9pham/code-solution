// Problem: 558 - Wormholes
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define INF 1e9
#define MAX 2025

typedef struct Edge{
	int u, v, w;
} Edge;

int dist[MAX];
Edge edge[MAX];
int n, m;

bool BellmanFord(int s){
	dist[s] = 0;
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < m; j++){
			if (dist[edge[j].v] > dist[edge[j].u] + edge[j].w){
				dist[edge[j].v] = dist[edge[j].u] + edge[j].w;
			}
		}
	}

	for (int j = 0; j < m; j++){
		if (dist[edge[j].v] > dist[edge[j].u] + edge[j].w)
			return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			dist[i] = INF;
		}
		for (int i = 0; i < m; i++){
			cin >> edge[i].u >> edge[i].v >> edge[i].w;
		}
		if (BellmanFord(0) == true){
			cout << "not possible" << endl;
		}
		else{
			cout << "possible" << endl;
		}
	}
	system("pause");
	return 0;
}