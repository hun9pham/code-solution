// Problem: UCV2013B - Alice in Amsterdam, I mean Wonderland
// Link: https://www.spoj.com/problems/UCV2013B/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>
#include <map>

using namespace std;

#define MAX 110
#define INF 1e9
typedef pair<int, int> pii;

int n, q;
string s[MAX];
int dist[MAX][MAX];

int main() {
	static int tc = 1;
	while (cin >> n){
		if (!n) break;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			for (int j = 0; j < n; j++){
				cin >> dist[i][j];
				if (i == j && dist[i][j] > 0) dist[i][j] = 0;
				if (dist[i][j] == 0 && i != j) dist[i][j] = INF;
			}
		}
		//Floyd Warshall
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (dist[i][k] != INF && dist[k][j] != INF){
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}
		bool flag = true;
		//Floyd Warshall check negative cycle
		for (int i = 0; i < n; i++){
			if (dist[i][i] < 0){
				flag = false;
				break;
			}
		}
		cin >> q;
		printf("Case #%d:\n", tc++);
		while (q--){
			int a, b;
			cin >> a >> b;
			if (!flag){
				cout << "NEGATIVE CYCLE" << endl;
			}
			else if (dist[a][b] == INF){
				cout << s[a] << '-' << s[b] << " NOT REACHABLE" << endl;
			}
			else{
				cout << s[a] << '-' << s[b] << ' ' << dist[a][b] << endl;
			}
		}
	}

	return 0;
}