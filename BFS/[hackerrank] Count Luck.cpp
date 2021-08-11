// Problem: Count Luck
// Link: https://www.hackerrank.com/contests/101feb14/challenges/count-luck
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct Pos{
	int x;//col
	int y;//row
	int k;
}Pos;

bool BFS_FUNC(Pos cur, int n, int m, int k, vector<string> M){//n row m col
	bool visited[110][110];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			visited[i][j] = false;
		}
	}
	int Step[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };//right left down up
	queue<Pos> q;
	q.push(cur);
	visited[cur.y][cur.x] = true;
	bool flag = false;
	while (!q.empty()){
		Pos next = q.front();
		q.pop();
		if (M[next.y][next.x] == '*'){
			if (next.k == k){
				flag = true;
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < 4; i++){
			int x = next.x + Step[i][0];
			int y = next.y + Step[i][1];
			if (visited[y][x] == false && x >= 0 && x < m && y >= 0 && y < n && M[y][x] != 'X'){
				cnt++;
			}
		}
		for (int i = 0; i < 4; i++){
			int x = next.x + Step[i][0];
			int y = next.y + Step[i][1];
			if (visited[y][x] == false && x >= 0 && x < m && y >= 0 && y < n && M[y][x] != 'X'){
				Pos new_pos;
				new_pos.x = x;
				new_pos.y = y;
				if (cnt>1){
					new_pos.k = next.k + 1;
				}
				else{
					new_pos.k = next.k;
				}
				q.push(new_pos);
				visited[y][x] = true;
			}
		}
	}
	return flag;
}

int main()
{
	int t;
	cin >> t;
	while (t-- > 0){
		int n, m; //rows and columns
		cin >> n >> m;
		vector<string> M;
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			M.push_back(s);
		}
		int k;
		cin >> k;
		Pos currentpos;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (M[i][j] == 'M'){
					currentpos = { j, i, 0 };
					break;
				}
			}
		}
		if (BFS_FUNC(currentpos, n, m, k, M)){
			cout << "Impressed" << endl;
		}
		else{
			cout << "Oops!" << endl;
		}
	}
	return 0;
}