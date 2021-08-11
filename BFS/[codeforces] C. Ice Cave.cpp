// Problem: C. Ice Cave
// Link: https://codeforces.com/problemset/problem/540/C
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 500

typedef struct Pos{
	int x; //col
	int y; //row
}Pos;

int Step[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } }; //right left down up

bool BFS_FUNC(Pos root, Pos des, int n, int m, vector<string> cave){ //n row m col
	bool visited[MAX][MAX];
	bool flag = false;
	queue<Pos> q;
	q.push(root);
	while (!q.empty()){
		Pos t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			int x = t.x + Step[i][0];
			int y = t.y + Step[i][1];
			if (x >= 0 && x < m && y >= 0 && y < n){
				if (cave[y][x] == 'X' && x == des.x && y == des.y){
					return true;
				}
			}
			else{
				continue;
			}
			if (cave[y][x] == '.'){
				cave[y][x] = 'X';
				Pos new_pos;
				new_pos.x = x;
				new_pos.y = y;
				q.push(new_pos);
			}
		}
	}
	return flag;
}

int main()
{
	int n, m;//rows and columns
	cin >> n >> m;
	vector<string> cave;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		cave.push_back(s);
	}
	int r1, c1, r2, c2;
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	--r1; --r2;
	--c1; --c2;
	Pos root = { c1, r1 };
	Pos des = { c2, r2 };
	if (BFS_FUNC(root, des, n, m, cave)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}