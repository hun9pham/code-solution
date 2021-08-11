// Problem: Event Organizer
// Link: https://www.codechef.com/problems/MAXCOMP
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define MAX 50
#define INF 1e9
typedef pair<int, int> pii;

int n;
int s, c, e;
int cost[MAX][MAX];

int main() {
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < n; i++){
			cin >> s >> e >> c;
			cost[s][e] = max(cost[s][e], c);
		}
		for (int k = 0; k <= 48; k++){
			for (int i = 0; i <= 48; i++){
				for (int j = 0; j <= 48; j++){
					if (i <= k && j >= k && cost[i][j] < cost[i][k] + cost[k][j]){
						cost[i][j] = cost[i][k] + cost[k][j];
					}
				}
			}
		}
		cout << cost[0][48] << endl;
	}

	return 0;
}