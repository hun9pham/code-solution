// Problem: ALLIZWEL - ALL IZZ WELL
// Link: https://www.spoj.com/problems/ALLIZWEL/en/
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

int r, c;
string input[110];
int Move[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 },
{ -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 } };
bool seen[110][110];
string s = "ALLIZZWELL";

typedef struct Coordinate{
	int x;
	int y;
}Coor;

bool isValid(int x, int y){
	return (x >= 0 && y >= 0 && x < r && y < c);
}

bool flag = false;
void dfs(int i, int j, int cnt){
	if (cnt == 9){
		flag = true;
		return;
	}
	for (int k = 0; k < 8; k++){
		int x = i + Move[k][1];
		int y = j + Move[k][0];
		if (isValid(x, y) && !seen[x][y] && input[x][y] == s[cnt + 1]){
			seen[x][y] = true;
			dfs(x, y, cnt + 1);
			seen[x][y] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--){
		cin >> r >> c;
		flag = false;
		memset(seen, false, sizeof(seen));
		for (int i = 0; i < r; i++){
			cin >> input[i];
		}
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (input[i][j] == 'A' && flag == false){
					seen[i][j] = true;
					dfs(i, j, 0);
					seen[i][j] = false;
					if (flag == true) break;
				}
			}
			if (flag == true) break;
		}
		if (flag == true){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}