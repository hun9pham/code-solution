// Problem: MAKEMAZE - VALIDATE THE MAZE
// Link: https://www.spoj.com/problems/MAKEMAZE/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define MAX 20

struct Position {
	int r, c;
};

int Step[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int n, m;
bool visited[MAX][MAX];
string maze[MAX];

bool isValid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

bool bfs(Position start, Position end) {
	queue<Position> q;
	q.push(start);
	visited[start.r][start.c] = true;
	while (!q.empty()){
		Position t = q.front();
		q.pop();
		if (t.c == end.c && t.r == end.r){
			return true;
		}
		for (int i = 0; i < 4; i++){
			int x = t.c + Step[i][0];
			int y = t.r + Step[i][1];
			if (isValid(y, x) && visited[y][x] == false && maze[y][x] == '.'){
				Position new_t = { y, x };
				q.push(new_t);
				visited[y][x] = true;
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t-->0){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> maze[i];
		}
		vector<Position> v;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				visited[i][j] = false;
				if (maze[i][j] == '.' && (i == 0 || j == 0 || i == n - 1 || j == m - 1)){
					Position p = { i, j };
					v.push_back(p);
				}
			}
		}
		if (v.size() != 2){
			cout << "invalid" << endl;
		}
		else{
			Position start = v[0];
			Position end = v[1];
			if (bfs(start, end)){
				cout << "valid" << endl;
			}
			else cout << "invalid" << endl;
		}
	}
	return 0;
}