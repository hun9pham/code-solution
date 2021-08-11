// Problem: 10986 - Sending email
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define MAX 20010
typedef pair<int, int> pii;

const int eps = 1e9;
int n, m, s, t;
vector <pii> message[MAX];
int dist[MAX];

struct AscendingSecond{
	bool operator ()(pii const& a, pii const& b){
		return a.second > b.second;
	}
};

void Dijsktra(int sr){
	priority_queue<pii, vector<pii>, AscendingSecond> pq;
	pq.push(make_pair(sr, 0));
	dist[sr] = 0;
	while (!pq.empty()){
		pii p = pq.top();
		pq.pop();
		int f = p.first;
		int s = p.second;
		for (auto it : message[f]){
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
	int tc;
	cin >> tc;
	static int Case = 1;
	while (tc--){
		cin >> n >> m >> s >> t;
		for (int i = 0; i < MAX; i++){
			dist[i] = eps;
			message[i].clear();
		}
		for (int i = 0; i < m; i++){
			int a, b, w;
			cin >> a >> b >> w;
			message[a].push_back(make_pair(b, w));
			message[b].push_back(make_pair(a, w));
		}
		Dijsktra(s);
		if (dist[t] == eps){
			printf("Case #%d: unreachable\n", Case++);
		}
		else{
			printf("Case #%d: %d\n", Case++, dist[t]);
		}
	}

	return 0;
}