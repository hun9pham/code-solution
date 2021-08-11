// Problem: 10653 - Bombs! NO they are Mines!!
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct Coordinate{
	int x; //row
	int y; //col
}Coor;
int r, c;
int srx, sry, desx, desy;
int Move[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
bool seen[1010][1010];
int path[1010][1010];
int map[1010][1010];

bool isValid(int x, int y){
	return (x >= 0 && y >= 0 && x < r && y < c);
}

void bfs(int srcx, int srcy){
	queue<Coor> q;
	Coor root = { srcx, srcy };
	q.push(root);
	seen[srcx][srcy] = true;
	while (!q.empty()){
		Coor t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++){
			int x = t.x + Move[i][1];
			int y = t.y + Move[i][0];
			if (isValid(x, y) && !seen[x][y] && map[x][y] != 1){
				Coor new_t = { x, y };
				q.push(new_t);
				seen[x][y] = true;
				path[x][y] = path[t.x][t.y] + 1;
			}
		}
	}
}

int main() {
	while (1){
		cin >> r >> c;
		if (r == 0 && c == 0) break;
		memset(seen, false, sizeof(seen));
		memset(path, 0, sizeof(path));
		memset(map, 0, sizeof(map));
		int numOfRowBombs;
		cin >> numOfRowBombs;
		for (int i = 0; i < numOfRowBombs; i++){
			int a, b;
			cin >> a >> b;
			for (int j = 0; j < b; j++){
				int x;
				cin >> x;
				map[a][x] = 1;
			}
		}
		cin >> srx >> sry;
		cin >> desx >> desy;
		bfs(srx, sry);
		cout << path[desx][desy] << endl;
	}
	return 0;
}