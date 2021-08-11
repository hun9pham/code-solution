// Problem: SHPATH - The Shortest Path
// Link: https://www.spoj.com/problems/SHPATH/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define MAX 1000010
typedef pair<int, int> pii;

const int eps = 1e9;
vector <pii> cities[MAX];
int dist[MAX];

struct AscendingSecond{
	bool operator ()(pii const& a, pii const& b){
		return a.second > b.second;
	}
};

void Dijsktra(int sr, int des){
	for (int h = 0; h < MAX; h++){
		dist[h] = eps;
	}
	priority_queue<pii, vector<pii>, AscendingSecond> pq;
	pq.push(make_pair(sr, 0));
	dist[sr] = 0;
	while (!pq.empty()){
		pii p = pq.top();
		pq.pop();
		int f = p.first;
		int s = p.second;
		for (auto it : cities[f]){
			int ff = it.first;
			int ss = it.second;
			int sum = ss + dist[f];
			if (sum < dist[ff]){
				dist[ff] = sum;
				pq.push(make_pair(ff, sum));
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		for (int h = 0; h < MAX; h++){
			cities[h].clear();
		}
		int n;
		cin >> n;
		map<string, int> cityIndex;
		for (int i = 1; i <= n; i++){
			string s;
			cin >> s;
			cityIndex[s] = i;
			int p;
			cin >> p;
			for (int j = 0; j < p; j++){
				int nr, cost;
				cin >> nr >> cost;
				cities[cityIndex[s]].push_back(make_pair(nr, cost));
			}
		}
		int k;
		cin >> k;
		while (k--){
			string src, des;
			cin >> src >> des;
			Dijsktra(cityIndex[src], cityIndex[des]);
			cout << dist[cityIndex[des]] << endl;
		}
	}

	return 0;
}