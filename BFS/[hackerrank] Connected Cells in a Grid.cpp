// Problem: Connected Cells in a Grid
// Link: https://www.hackerrank.com/contests/springsprint/challenges/connected-cell-in-a-grid
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 10

typedef struct Position{
	int r;//row
	int c;//col
}Position;

int board[MAX][MAX];
bool visited[250][250];
int istart, jstart;
int ides, jdes;
int Step[8][2] = { 
	{ 1, 0 }, // right
	{ -1, 0 }, // left
	{ 0, 1 }, // up
	{ 0, -1 }, // down
	{ 1, 1 }, // down right
	{ -1, 1 }, // down left
	{ 1, -1 }, // up right
	{ -1, -1 } // up left
};
int n, m;
int region[MAX][MAX];

bool isValid(int r, int c){
	return (r >= 0 && r < n && c >= 0 && c < m);
}

int bfs(Position root){
	int cnt = 0;
	queue <Position> q;
	q.push(root);
	visited[root.r][root.c] = true;
	while (!q.empty()){
		Position t = q.front();
		if (region[t.r][t.c] == 1){
			cnt++;
		}
		q.pop();
		for (int i = 0; i < 8; i++){
			int nc = t.c + Step[i][0];
			int nr = t.r + Step[i][1];
			if (isValid(nr, nc) && visited[nr][nc] == false && region[nr][nc] == 1){
				Position new_t = { nr, nc };
				visited[nr][nc] = true;
				q.push(new_t);
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> region[i][j];
			visited[i][j] = false;
		}
	}
	vector < int> vregion;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (region[i][j] == 1 && visited[i][j] == false){
				Position root = { i, j };
				vregion.push_back(bfs(root));
			}
		}
	}
	cout << *max_element(vregion.begin(), vregion.end()) << endl;
	return 0;
}