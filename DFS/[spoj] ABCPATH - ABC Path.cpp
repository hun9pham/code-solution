// Problem: ABCPATH - ABC Path
// Link: https://www.spoj.com/problems/ABCPATH/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 55
typedef long long int ll;
typedef struct Coordinate{
	int r;
	int c;
}Coor;

int W, H;
int cnt = 0;
bool seen[MAX][MAX];
string letters_map[MAX];
int path[MAX][MAX];

int Move[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 },
{ -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 } };

bool isValid(int r, int c){
	return (r >= 0 && c >= 0 && r < H && c < W);
}

void dfs(int r, int c){
	stack<Coor> st;
	Coor root = { r, c };
	st.push(root);
	seen[r][c] = true;
	path[r][c] = 1;
	while (!st.empty()){
		Coor top = st.top();
		st.pop();
		for (int i = 0; i < 8; i++){
			int cc = top.c + Move[i][0];
			int rr = top.r + Move[i][1];
			if (isValid(rr, cc) && !seen[rr][cc] && letters_map[rr][cc] == letters_map[top.r][top.c] + 1){
				Coor new_top = { rr, cc };
				//cout << letters_map[rr][cc] << endl;
				path[rr][cc] = path[top.r][top.c] + 1;
				st.push(new_top);
				seen[rr][cc] = true;
			}
		}
	}
}

int main() {
	static int test_case = 1;
	while (1){
		cin >> H >> W;
		if (W == 0 && H == 0) break;
		memset(seen, false, sizeof(seen));
		memset(path, 0, sizeof(path));
		for (int i = 0; i < H; i++){
			cin >> letters_map[i];
		}
		int kq = 0;
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if (letters_map[i][j] == 'A'){
					cnt = 0;
					dfs(i, j);
				}
			}
		}
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				kq = max(kq, path[i][j]);
			}
		}
		cout << "Case " << test_case << ": " << kq << endl;
		test_case++;
	}
	return 0;
}