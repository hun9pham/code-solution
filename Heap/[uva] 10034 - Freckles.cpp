// Problem: 10034 - Freckles
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

#define MAX 10000

double x[MAX];
double y[MAX];

typedef struct Coordinate{
	int point;
	double len;
}Coor;

double Distance(double x1, double y1, double x2, double y2){
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
bool operator < (Coor a, Coor b){
	return a.len > b.len;
}

int main() {
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<Coor> v[MAX];
		for (int i = 0; i < n; i++){
			double a, b;
			cin >> a >> b;
			x[i] = a;
			y[i] = b;
		}
		for (int i = 0; i < n - 1; i++){
			for (int j = i + 1; j < n; j++){
				double k = Distance(x[i], y[i], x[j], y[j]);
				Coor c1 = { j, k };
				v[i].push_back(c1);
				Coor c2 = { i, k };
				v[j].push_back(c2);
			}
		}
		priority_queue<Coor> q;
		Coor root = { 0, 0 };
		q.push(root);
		bool seen[MAX];
		memset(seen, false, sizeof(seen));
		double kq = 0;
		while (!q.empty()){
			int d = q.top().point;
			double l = q.top().len;
			q.pop();
			if (seen[d] == true) continue;
			kq += l;
			seen[d] = true;
			for (int i = 0; i < v[d].size(); i++){
				int new_d = v[d][i].point;
				if (seen[new_d] == false){
					q.push(v[d][i]);
				}
			}
		}
		if (t > 0)
			printf("%.2f\n\n", kq);
		else
			printf("%.2f\n", kq);
	}
	return 0;
}