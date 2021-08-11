// Problem: 12144 - Almost Shortest Path
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3296
// Author: Pham Nguyen Quoc Hung

#include <bits/stdc++.h>

using namespace std;

#define MAX 550
typedef pair<int, int> pii;

int n, m;
vector<pii> StoD[MAX], DtoS[MAX];
int costS[MAX], costD[MAX], COST[MAX];

struct AscendingSecond{
	bool operator ()(pii const& a, pii const& b){
		return a.second > b.second;
	}
};

void Dijkstra(int src, int des, vector<pii> Vec[], int *pdist, bool flag){
	priority_queue<pii, vector<pii>, AscendingSecond> pq;
	pq.push(make_pair(src, 0));
	pdist[src] = 0;
	while (!pq.empty()){
		pii p = pq.top();
		pq.pop();
		for (auto it : Vec[p.first]){
			int index = it.first;
			int cost = it.second;
			if (!flag){
				int sum = cost + p.second;
				if (sum < pdist[index]){
					pdist[index] = sum;
					pq.push(make_pair(index, sum));
				}
			}
			else{
				if (costS[p.first] + cost + costD[index] != costS[des] && pdist[index] > pdist[p.first] + cost){
					pdist[index] = pdist[p.first] + cost;
					pq.push(make_pair(index, pdist[index]));
				}
			}
		}
	}
}

int main()
{
	while (1){
		cin >> n >> m;
		if (!n && !m) break;
		for (int i = 0; i<n; i++){
			StoD[i].clear();
			DtoS[i].clear();
			costS[i] = costD[i] = COST[i] = INT_MAX;
		}
		int s, d;
		cin >> s >> d;
		for (int i = 0; i<m; i++){
			int a, b, w;
			cin >> a >> b >> w;
			StoD[a].push_back(make_pair(b, w));
			DtoS[b].push_back(make_pair(a, w));
		}
		bool flag = false;
		Dijkstra(s, d, StoD, costS, flag);
		Dijkstra(d, s, DtoS, costD, flag);
		flag = true;
		Dijkstra(s, d, StoD, COST, flag);
		if (COST[d] == INT_MAX){
			cout << -1 << endl;
		}
		else cout << COST[d] << endl;
	}

	return 0;
}