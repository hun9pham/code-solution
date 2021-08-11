// Problem: TRAFFICN - Traffic Network
// Link: https://www.spoj.com/problems/TRAFFICN/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define MAX 10010
typedef pair<int, int> pii;

const int eps = 1e9;
int n, m, k, s, t, u, v, T, d, ans;
vector< vector<pii> > v1, v2;
vector<int> ds, dt;
pii temp;

struct AscendingSecond{
	bool operator ()(pii const& a, pii const& b){
		return a.second > b.second;
	}
};

void Dijsktra(int start, vector<int> &dist, vector< vector<pii> > &vv)
{
	priority_queue<pii, vector<pii>, AscendingSecond> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();
		d = temp.first;
		u = temp.second;
		if (dist[u]<d)
			continue;
		for (int i = 0; i<vv[u].size(); i++)
		{
			temp = vv[u][i];
			d = temp.second;
			v = temp.first;
			if (dist[u] + d < dist[v])
			{
				dist[v] = dist[u] + d;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> k >> s >> t;
		v1.clear();
		v1.resize(n + 1);
		v2.clear();
		v2.resize(n + 1);
		ds.assign(n + 1, eps);
		dt.assign(n + 1, eps);
		for (int i = 0; i<m; i++)
		{
			cin >> u >> v >> d;
			v1[u].push_back(make_pair(v, d));
			v2[v].push_back(make_pair(u, d));
		}
		Dijsktra(s, ds, v1);
		Dijsktra(t, dt, v2);
		ans = eps;
		for (int i = 0; i<k; i++)
		{
			cin >> u >> v >> d;
			ans = min(ds[t], min(ans, d + min(ds[u] + dt[v], ds[v] + dt[u])));
		}
		if (ans == eps) {
			cout << -1 << endl;
		}
		else cout << ans << endl;
	}

	return 0;
}