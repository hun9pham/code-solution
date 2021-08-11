// Problem: SOCIALNE - Possible Friends
// Link: https://www.spoj.com/problems/SOCIALNE/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define MAX 50
#define INF 1e9
typedef pair<int, int> pii;
typedef long long int lli;

string s;
string friends[MAX];
int arr[MAX][MAX];
int check[MAX][MAX];

int main() {
	int t;
	cin >> t;
	while (t--){
		cin >> s;
		friends[0] = s;
		for (int i = 1; i < s.length(); i++){
			cin >> friends[i];
		}
		memset(check, 0, sizeof(check));
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < s.length(); i++){
			for (int j = 0; j < s.length(); j++){
				if (friends[i][j] == 'Y'){
					arr[i][j] = 1;
					check[i][j] = 1;
				}
			}
		}
		for (int k = 0; k < s.length(); k++){
			for (int i = 0; i < s.length(); i++){
				for (int j = 0; j < s.length(); j++){
					if (arr[i][k] == 1 && arr[k][j] == 1){
						check[i][j] = 1;
					}
				}
			}
		}
		int index = 0;
		int maxFriends = 0;
		for (int i = 0; i < s.length(); i++){
			int cnt = 0;
			for (int j = 0; j < s.length(); j++){
				if (i != j && arr[i][j] == 0 && check[i][j] == 1){
					cnt++;
				}
			}
			if (maxFriends < cnt){
				index = i;
				maxFriends = cnt;
			}
		}
		cout << index << ' ' << maxFriends << endl;
	}

	return 0;
}