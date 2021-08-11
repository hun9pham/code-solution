// Problem: D. Lakes in Berland
// Link: https://codeforces.com/problemset/problem/723/D
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 50
typedef long long int ll;

bool seen[MAX][MAX];
vector<string> berland;
int row, col, k;
int step[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } }; //left right up down
typedef struct Coordinate{
	int r;
	int c;
	int s; //Dien tich
}Coor;

bool comp(Coor a, Coor b){
	return a.s < b.s;
}

bool isValid(int tr, int tc){
	return (tr >= 0 && tc >= 0 && tr < row && tc < col);
}

int dfs_lake(int i, int j){
	int cnt = 0;
	stack<Coor> st;
	Coor root = { i, j };
	st.push(root);
	seen[root.r][root.c] = true;
	while (!st.empty()){
		Coor t = st.top();
		st.pop();
		if (berland[t.r][t.c] == '.'){
			cnt++;
		}
		for (int i = 0; i < 4; i++){
			int tr = t.r + step[i][1];
			int tc = t.c + step[i][0];
			if (isValid(tr, tc) && !seen[tr][tc] && berland[tr][tc] == '.'){
				Coor new_t = { tr, tc };
				seen[tr][tc] = true;
				st.push(new_t);
			}
		}
	}
	return cnt;
}
void dfs_earth(int i, int j){
	stack<Coor> st;
	Coor root = { i, j };
	st.push(root);
	seen[root.r][root.c] = true;
	while (!st.empty()){
		Coor t = st.top();
		st.pop();
		if (berland[t.r][t.c] == '.'){
			berland[t.r][t.c] = '*';
		}
		for (int i = 0; i < 4; i++){
			int tr = t.r + step[i][1];
			int tc = t.c + step[i][0];
			if (isValid(tr, tc) && !seen[tr][tc] && berland[tr][tc] == '.'){
				Coor new_t = { tr, tc };
				seen[tr][tc] = true;
				st.push(new_t);
			}
		}
	}
}

void OceanSearch(Coor root){
	stack<Coor> st;
	st.push(root);
	seen[root.r][root.c] = true;
	while (!st.empty()){
		Coor t = st.top();
		st.pop();
		for (int i = 0; i < 4; i++){
			int tr = t.r + step[i][1];
			int tc = t.c + step[i][0];
			if (isValid(tr, tc) && !seen[tr][tc] && berland[tr][tc] == '.'){
				Coor new_t = { tr, tc };
				seen[tr][tc] = true;
				st.push(new_t);
			}
		}
	}
}

int main() {
	memset(seen, false, sizeof(seen));
	cin >> row >> col >> k;
	for (int i = 0; i < row; i++){
		string s;
		cin >> s;
		berland.push_back(s);
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (berland[i][j] == '.' && (i == 0 || i == row - 1 || j == 0 || j == col - 1)){
				Coor root = { i, j };
				OceanSearch(root);
			}
		}
	}
	int total = 0;
	vector<Coor> lake;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (berland[i][j] == '.' && seen[i][j] == false){
				int area = dfs_lake(i, j);
				Coor root = { i, j, area };
				lake.push_back(root);
				total++;
			}
		}
	}
	sort(lake.begin(), lake.end(), comp);
	memset(seen, false, sizeof(seen));
	int all = 0;
	for (int i = 0; i < total - k; i++){
		all += lake[i].s;
		dfs_earth(lake.at(i).r, lake.at(i).c);
	}
	cout << all << endl;
	for (int i = 0; i < row; i++){
		cout << berland[i] << endl;
	}
	return 0;
}