// Problem: KOZE - Sheep
// Link: https://www.spoj.com/problems/KOZE/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 200

typedef struct Animals{
	int r; //row
	int c; //col
}Animals;

bool visited[250][250];
int Step[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } }; //right left down up
int r, c; //row & col
vector<string> backyard;
int cnt_wolf = 0;
int cnt_sheep = 0;
int k = 0;
int v = 0;

bool isValid(int xr, int xc, int r, int c){
	return (xr >= 0 && xr < r && xc >= 0 && xc < c);
}

void dfs(Animals root){
	stack<Animals> st;
	st.push(root);
	visited[root.r][root.c] = true;
	while (!st.empty()){
		Animals a = st.top();
		st.pop();
		if (backyard[a.r][a.c] == 'v'){
			v++;
		}
		else if (backyard[a.r][a.c] == 'k'){
			k++;
		}
		for (int i = 0; i < 4; i++){
			int xc = a.c + Step[i][0];
			int xr = a.r + Step[i][1];
			if (visited[xr][xc] == false && isValid(xr, xc, r, c) && backyard[xr][xc] != '#'){
				Animals new_w = { xr, xc };
				st.push(new_w);
				visited[xr][xc] = true;
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++){
		string s;
		cin >> s;
		backyard.push_back(s);
	}
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			visited[i][j] = false;
			if (backyard[i][j] == 'k'){
				cnt_sheep++;
			}
			else if (backyard[i][j] == 'v'){
				cnt_wolf++;
			}
		}
	}
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (backyard[i][j] == 'k' && visited[i][j] == false){
				k = 0;
				v = 0;
				Animals root = { i, j };
				dfs(root);
				if (v >= k){
					cnt_sheep = cnt_sheep - k;
				}
				else{
					cnt_wolf = cnt_wolf - v;
				}
			}
		}
	}
	cout << cnt_sheep << ' ' << cnt_wolf << endl;
	return 0;
}