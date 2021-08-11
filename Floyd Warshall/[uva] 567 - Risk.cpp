// Problem: 567 - Risk
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=508
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 30
#define INF 1e9
typedef pair<int, int> pii;

int n, m;
int start, des;
int dist[MAX][MAX];

int main() {
	static int tc = 1;
	while (cin >> n){
		if (!n) break;
		for (int i = 1; i <= 20; i++){
			for (int j = 1; j <= 20; j++){
				if (i == j) dist[i][j] = 0;
				else{
					dist[i][j] = INF;
				}
			}
		}
		for (int i = 0; i<n; i++){
			int a;
			cin >> a;
			dist[1][a] = 1;
			dist[a][1] = 1;
		}
		for (int i = 2; i <= 19; i++){
			int a;
			cin >> a;
			for (int j = 0; j<a; j++){
				int b;
				cin >> b;
				dist[i][b] = 1;
				dist[b][i] = 1;
			}
		}
		for (int k = 1; k <= 20; k++){
			for (int i = 1; i <= 20; i++){
				for (int j = 1; j <= 20; j++){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		cin >> m;
		printf("Test Set #%d\n", tc++);
		while (m--){
			cin >> start >> des;
			printf("%2d to %2d: %d\n", start, des, dist[start][des]);
		}
		cout << endl;
	}

	return 0;
}