// Problem: Red Knight's Shortest Path
// Link: https://www.hackerrank.com/contests/world-codesprint-12/challenges/red-knights-shortest-path
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 200

typedef struct Position{
	int r;//row
	int c;//col
}Position;

int board[MAX][MAX];
bool visited[250][250];
int istart, jstart;
int ides, jdes;
int Move[6][2] = { { -1, -2 }, { 1, -2 }, { 2, 0 }, { 1, 2 }, { -1, 2 }, { -2, 0 } }; //UL, UR, R, LR, LL, L.
string path[MAX][MAX];
Position PATH[MAX][MAX];
int n;

bool isValid(int pr, int pc, int n){
	return (pr >= 0 && pr < n && pc >= 0 && pc < n);
}

void bfs(Position root){
	queue <Position> q;
	q.push(root);
	visited[root.r][root.c] = true;
	board[root.r][root.c] = 0;
	while (!q.empty()){
		Position t = q.front();
		q.pop();
		for (int i = 0; i < 6; i++){
			int nc = t.c + Move[i][0];
			int nr = t.r + Move[i][1];
			if (isValid(nr, nc, n) && visited[nr][nc] == false){
				switch (i)//UL, UR, R, LR, LL, L.
				{
				case 0:
					path[nr][nc] = "UL";
					break;
				case 1:
					path[nr][nc] = "UR";
					break;
				case 2:
					path[nr][nc] = "R";
					break;
				case 3:
					path[nr][nc] = "LR";
					break;
				case 4:
					path[nr][nc] = "LL";
					break;
				case 5:
					path[nr][nc] = "L";
					break;
				}
				Position new_t = { nr, nc };
				q.push(new_t);
				visited[nr][nc] = true;
				PATH[nr][nc] = t;
				board[nr][nc] = board[t.r][t.c] + 1;
			}
		}
	}
	if (board[ides][jdes] == 0){
		cout << "Impossible" << endl;
	}
	else{
		cout << board[ides][jdes] << endl;
		vector<string> vs;
		int y = ides, x = jdes;
		while (1){
			if (x == jstart && y == istart) break;
			vs.push_back(path[y][x]);
			int new_x = PATH[y][x].c;
			int new_y = PATH[y][x].r;
			y = new_y;
			x = new_x;
		}
		reverse(vs.begin(), vs.end());
		for (vector<string>::iterator it = vs.begin(); it != vs.end(); it++){
			cout << *it << ' ';
		}
		cout << endl;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			visited[i][j] = false;
		}
	}
	cin >> istart >> jstart >> ides >> jdes;
	Position root = { istart, jstart };
	board[istart][jstart] = 0;
	board[ides][jdes] = 0;
	bfs(root);
	return 0;
}