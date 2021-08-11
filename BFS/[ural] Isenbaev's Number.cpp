// Problem: Isenbaev's Number
// Link: https://vjudge.net/problem/URAL-1837
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>
#include <map>

using namespace std;

#define MAX 110
#define INF 1e9
typedef pair<int, int> pii;

int n;
map<string, int> Id;
string Name[MAX][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			cin >> Name[i][j];
			Id[Name[i][j]] = -1;
		}
	}
	if (Id.find("Isenbaev") != Id.end()){
		Id["Isenbaev"] = 0;
	}
	queue<string> q;
	q.push("Isenbaev");
	while (!q.empty()){
		string s = q.front();
		q.pop();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 3; j++){
				if (Name[i][j] == s){
					for (int k = 0; k < 3; k++){
						if (k != j && Id[Name[i][k]] == -1){
							Id[Name[i][k]] = Id[s] + 1;
							q.push(Name[i][k]);
						}
					}
					break;
				}
			}
		}
	}
	for (auto it : Id){
		cout << it.first << ' ';
		if (it.second == -1) cout << "undefined" << endl;
		else cout << Id[it.first] << endl;
	}

	return 0;
}