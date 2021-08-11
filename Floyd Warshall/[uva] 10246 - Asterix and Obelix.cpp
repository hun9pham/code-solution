// Problem: 10246 - Asterix and Obelix
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1187
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 1005
#define INF 1e9
typedef pair<int, int> pii;

struct costFeast{
	int cost;
	int index;
};

int c, r, q;
costFeast feast[MAX];
int dist[MAX][MAX];
int cost[MAX][MAX];
int c1, c2, d;

bool comp(costFeast a, costFeast b){
	return a.cost < b.cost;
}

void floyd(){
	for (int k = 1; k <= c; k++){
		for (int i = 1; i <= c; i++){
			for (int j = 1; j <= c; j++){
				int ii = feast[i].index;
				int jj = feast[j].index;
				int kk = feast[k].index;
				dist[ii][jj] = min(dist[ii][jj], dist[ii][kk] + dist[kk][jj]);
				cost[ii][jj] = min(cost[ii][jj], dist[ii][jj] +
					max(feast[i].cost, max(feast[j].cost, feast[k].cost)));
			}
		}
	}
}

int main() {
	static int tc = 1;
	while (1){
		cin >> c >> r >> q;
		if (!c && !r && !q) break;
		for (int i = 1; i <= c; i++){
			for (int j = 1; j <= c; j++){
				if (i == j) {
					dist[i][j] = 0;
					cost[i][j] = 0;
				}
				else{
					dist[i][j] = INF;
					cost[i][j] = INF;
				}
			}
		}
		for (int i = 1; i <= c; i++){
			cin >> feast[i].cost;
			feast[i].index = i;
		}
		sort(feast + 1, feast + c + 1, comp);
		for (int i = 1; i <= r; i++){
			cin >> c1 >> c2 >> d;
			dist[c1][c2] = dist[c2][c1] = d;
		}
		floyd();
		if (tc>1)
			cout << endl;
		printf("Case #%d\n", tc++);
		while (q--){
			cin >> c1 >> c2;
			if (cost[c1][c2] == INF){
				cout << -1 << endl;;
			}
			else{
				cout << cost[c1][c2] << endl;;
			}
		}
	}

	return 0;
}