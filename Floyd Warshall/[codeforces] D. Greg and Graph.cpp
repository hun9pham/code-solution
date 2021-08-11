// Problem: D. Greg and Graph
// Link: https://codeforces.com/problemset/problem/296/D
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 555
#define INF 1e9
typedef pair<int, int> pii;

int main() {
	int n;
	int dist[MAX][MAX];
	int Delete[MAX];
	long long int res[MAX];
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> dist[i][j];
		}
	}
	for (int i = n; i >= 1; i--){
		cin >> Delete[i];
	}
	for (int k = 1; k <= n; k++){
		int x = Delete[k];
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);
			}
		}
		for (int h = 1; h <= k; h++){
			for (int o = 1; o <= k; o++){
				res[k] += dist[Delete[h]][Delete[o]];
			}
		}
	}
	for (int i = n; i >= 1; i--){
		cout << res[i] << ' ';
	}

	return 0;
}