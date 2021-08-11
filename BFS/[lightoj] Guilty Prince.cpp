// Problem: Guilty Prince
// Link: https://lightoj.com/problem/guilty-prince
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 101000

int MAXCOL;
int MAXROW;
bool visited[20][20];
int step[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

typedef struct Pos{
	int x; //col
	int y; //row
}Pos;


int BFS_FUNC(vector<string> map, int col, int row){
	int cnt = 1;
	bool flag = true;
	//memset(visited, false, sizeof(visited));
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			visited[i][j] = false;
		}
	}
	queue<Pos> q;
	Pos root;
	root.x = col;
	root.y = row;
	q.push(root);
	while (!q.empty()){
		Pos t = q.front();
		q.pop();
		if (visited[t.y][t.x] == true) continue;
		if (flag == false){
			cnt++;
		}
		flag = false;
		visited[t.y][t.x] = true;
		for (int i = 0; i < sizeof(step) / sizeof(step[0]); i++){
			int test_x = step[i][0] + t.x;
			int test_y = step[i][1] + t.y;
			if (test_x >= 0 && test_x < MAXCOL
				&& test_y >= 0 && test_y < MAXROW && map[test_y][test_x] != '#'){
				Pos next_step = { test_x, test_y };
				q.push(next_step);
			}
		}
	}
	return cnt;
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++){
		int col, row;
		cin >> col >> row;
		MAXCOL = col;
		MAXROW = row;
		vector<string> map;
		for (int i = 0; i < row; i++){
			string s;
			cin >> s;
			map.push_back(s);
		}
		int root_col, root_row;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (map[i][j] == '@'){
					root_col = j;
					root_row = i;
				}
			}
		}
		cout << "Case " << k << ": " << BFS_FUNC(map, root_col, root_row) << endl;
	}
	return 0;
}