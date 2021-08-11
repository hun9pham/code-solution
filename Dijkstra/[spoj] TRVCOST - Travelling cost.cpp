// Problem: TRVCOST - Travelling cost
// Link: https://www.spoj.com/problems/TRVCOST/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 550
typedef pair<int, int> pii;

const int eps = 1e9;
int n, a, b, w, q, u, v;
vector <pii> roads[MAX];
int cost[MAX];

struct AscendingSecond{
	bool operator ()(pii const& a, pii const& b){
		return a.second > b.second;
	}
};

void Dijsktra(int i, int j){
	priority_queue<pii, vector<pii>, AscendingSecond> pq;
	pq.push(make_pair(i, j));
	cost[i] = 0;
	while (!pq.empty()){
		pii p = pq.top();
		pq.pop();
		for (int i = 0; i < roads[p.first].size(); i++){
			int Cost = p.second + roads[p.first][i].second;
			if (Cost < cost[roads[p.first][i].first]){
				cost[roads[p.first][i].first] = Cost;
				pq.push(make_pair(roads[p.first][i].first, Cost));
			}
		}
	}

}

int main(){
	cin >> n;
	for (int i = 0; i < MAX; i++){
		cost[i] = eps;
	}
	for (int i = 0; i < n; i++){
		cin >> a >> b >> w;
		roads[a].push_back(make_pair(b, w));
		roads[b].push_back(make_pair(a, w));
	}
	cin >> u;
	Dijsktra(u, 0);
	cin >> q;
	while (q--){
		cin >> v;
		if (cost[v] != eps){
			cout << cost[v] << endl;
		}
		else cout << "NO PATH" << endl;
	}
	return 0;
}