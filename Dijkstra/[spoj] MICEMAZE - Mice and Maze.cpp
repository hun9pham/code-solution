// Problem: MICEMAZE - Mice and Maze
// Link: https://www.spoj.com/problems/MICEMAZE/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 150
typedef pair<int, int> pii;

const int eps = 1e9;
int N, E, T, M;
int a, b, t;
vector <pii> maze[MAX];
int dist[MAX];
int cnt = 0;

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
		for (int i = 0; i < maze[f].size(); i++){
			int ff = maze[f][i].first;
			int ss = maze[f][i].second;
			int sum = ss + dist[f];
			if (dist[ff] > sum){
				dist[ff] = sum;
				pq.push(make_pair(ff, dist[ff]));
			}
		}
	}
}

int main(){
	cin >> N >> E >> T;
	cin >> M;
	for (int i = 0; i < MAX; i++){
		dist[i] = eps;
		maze[i].clear();
	}
	for (int i = 0; i < M; i++){
		cin >> a >> b >> t;
		maze[b].push_back(make_pair(a, t));
	}
	Dijsktra(E);
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		if (dist[i] <= T){
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}