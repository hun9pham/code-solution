// Problem: UCV2013H - Slick
// Link: https://www.spoj.com/problems/UCV2013H/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define MAX 250

typedef struct Position{
	int r; //row
	int c; //col
}Position;

int area[MAX][MAX];
bool visited[MAX][MAX];
int total = 0;
int r, c;
int Move[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };//right left down up

bool isValid(int hang, int cot, int r, int c){
	return (hang >= 0 && cot >= 0 && hang < r && cot < c);
}

int bfs(Position root){
	queue<Position> q;
	int cnt = 0;
	q.push(root);
	visited[root.r][root.c] = true;
	while (!q.empty()){
		Position pos = q.front();
		if (area[pos.r][pos.c] == 1){
			cnt++;
		}
		q.pop();
		for (int i = 0; i < 4; i++){
			int cot = pos.c + Move[i][0];
			int hang = pos.r + Move[i][1];
			if (visited[hang][cot] == false && isValid(hang, cot, r, c)
				&& area[hang][cot] == 1){
				Position new_pos = { hang, cot };
				q.push(new_pos);
				visited[hang][cot] = true;
			}
		}
	}
	return cnt;
}

int main()
{
	while (1){
		cin >> r >> c;
		if (r == 0 && c == 0) break;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cin >> area[i][j];
				visited[i][j] = false;
			}
		}
		map<int, int> kq;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (area[i][j] == 1 && visited[i][j] == false){
					Position root = { i, j };
					kq[bfs(root)]++;
				}
			}
		}
		for (map<int, int>::iterator it = kq.begin(); it != kq.end(); it++){
			total += (*it).second;
		}
		cout << total << endl;
		for (map<int, int>::iterator it = kq.begin(); it != kq.end(); it++){
			cout << (*it).first << ' ' << (*it).second << endl;
		}
		total = 0;
	}
	return 0;
}