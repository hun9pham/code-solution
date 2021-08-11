// Problem: KnightL on a Chessboard
// Link: https://www.hackerrank.com/contests/rookierank-2/challenges/knightl-on-chessboard
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct KnightL{
	int x;
	int y;
}KnightL;

int BFS_FUNC(int a, int b, int n){// x + a && y + b
	queue<KnightL> q;
	bool visited[25][25];
	int Move[25][25];
	int dx[] = { a, a, -a, -a, b, b, -b, -b };
	int dy[] = { b, -b, b, -b, a, -a, a, -a };
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			visited[i][j] = false;
		}
	}
	KnightL firtpos = { 0, 0 };
	q.push(firtpos);
	visited[firtpos.y][firtpos.x] = true;
	Move[firtpos.y][firtpos.x] = 0;
	while (!q.empty()){
		KnightL k = q.front();
		q.pop();
		int x = k.x;
		int y = k.y;
		for (int i = 0; i < 8; i++){
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n){
				if (visited[y + dy[i]][x + dx[i]] == false){
					visited[y + dy[i]][x + dx[i]] = true;
					Move[y + dy[i]][x + dx[i]] = Move[y][x] + 1;
					KnightL _move = { x + dx[i], y + dy[i] };
					q.push(_move);
				}
			}
		}
	}
	if (visited[n - 1][n - 1] == false){
		return -1;
	}
	else{
		return Move[n - 1][n - 1];
	}
}

int main()
{
	int n;
	cin >> n;
	for (int a = 1; a < n; a++){
		for (int b = 1; b < n; b++){
			cout << BFS_FUNC(a, b, n) << ' ';
		}
		cout << endl;
	}
	return 0;
}