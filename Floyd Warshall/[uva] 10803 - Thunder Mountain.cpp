// Problem: 10803 - Thunder Mountain
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1744
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

#define INF 1e9
#define MAX 100055
typedef pair<int, int> pii;

typedef struct Coordinate{
	double x;
	double y;
}Coor;

int main(){
	int t;
	int test_case = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		Coor town[110];
		double dist[110][110];
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				dist[i][j] = INT_MAX;
			}
		}
		for (int i = 0; i<n; i++){
			cin >> town[i].x >> town[i].y;
			for (int j = 0; j<i; j++){
				double distance = hypot(town[i].x - town[j].x, town[i].y - town[j].y);
				if (distance <= 10){
					dist[i][j] = dist[j][i] = distance;
				}
			}
		}
		//FloydWarshall
		for (int k = 0; k<n; k++){
			for (int i = 0; i<n; i++){
				for (int j = 0; j<n; j++){
					if (dist[i][k] + dist[k][j] < dist[i][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		double res = 0;
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				res = max(res, dist[i][j]);
			}
		}
		if (res == INT_MAX){
			printf("Case #%d:\n", test_case++);
			printf("Send Kurdy\n");
		}
		else{
			printf("Case #%d:\n", test_case++);
			printf("%.4lf\n", res);
		}
		cout << endl;

	}

	return 0;
}