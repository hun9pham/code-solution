// Problem: 436 - Arbitrage (II)
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=377
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define MAX 35
#define INF 1e9

struct Currency{
	string type;
	int index;
};
int n, m;
double dist[MAX][MAX];
struct Currency curr[MAX];

int IndexReturn(string str){
	int index = 0;
	for (int i = 0; i < n; i++){
		if (curr[i].type == str){
			index = curr[i].index;
			break;
		}
	}
	return index;
}

void Floyd(){
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (dist[i][j] < dist[i][k] * dist[k][j]){
					dist[i][j] = dist[i][k] * dist[k][j];
				}
			}
		}
	}
}

int main() {
	static int tc = 1;
	while (cin >> n){
		if (!n) break;
		memset(dist, 0, sizeof(dist));
		for (int i = 0; i < n; i++){
			cin >> curr[i].type;
			curr[i].index = i;
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			string ci, cj;
			double rij;
			cin >> ci;
			cin >> rij;
			cin >> cj;
			dist[IndexReturn(ci)][IndexReturn(cj)] = rij;
		}
		Floyd();
		bool flag = false;
		for (int i = 0; i < n; i++){
			if (dist[i][i] > 1.0){
				flag = true;
			}
		}
		if (flag){
			printf("Case %d: Yes\n", tc++);
		}
		else printf("Case %d: No\n", tc++);
	}

	return 0;
}