// Problem: 10171 - Meeting Prof. Miguel
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1112
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define MAX 30
#define INF 1e9
typedef pair<int, int> pii;

int n;
char YM, UB, X, Y;
int C;
int Me[MAX][MAX];
int Prof[MAX][MAX];

void init(){
	for (int i = 0; i<MAX; i++){
		for (int j = 0; j<MAX; j++){
			if (i == j){
				Me[i][j] = Prof[i][j] = 0;
			}
			else{
				Me[i][j] = Prof[i][j] = INF;
			}
		}
	}
}

void floyd(){
	for (int k = 0; k<26; k++){
		for (int i = 0; i<26; i++){
			for (int j = 0; j<26; j++){
				Me[i][j] = min(Me[i][j], Me[i][k] + Me[k][j]);
				Prof[i][j] = min(Prof[i][j], Prof[i][k] + Prof[k][j]);
			}
		}
	}
}

int main() {
	while ((cin >> n) && n > 0){
		init();
		for (int i = 0; i<n; i++){
			cin >> YM >> UB >> X >> Y;
			cin >> C;
			if (YM == 'Y'){
				Me[X - 'A'][Y - 'A'] = min(C, Me[X - 'A'][Y - 'A']);
				if (UB == 'B'){
					Me[Y - 'A'][X - 'A'] = min(C, Me[Y - 'A'][X - 'A']);
				}
			}
			else{
				Prof[X - 'A'][Y - 'A'] = min(C, Prof[X - 'A'][Y - 'A']);
				if (UB == 'B'){
					Prof[Y - 'A'][X - 'A'] = min(C, Prof[Y - 'A'][X - 'A']);
				}
			}
		}
		floyd();
		char myPos, profPos;
		cin >> myPos >> profPos;
		int res = INF;
		for (int i = 0; i<26; i++){
			res = min(res, Me[myPos - 'A'][i] + Prof[profPos - 'A'][i]);
		}
		if (res == INF){
			cout << "You will never meet." << endl;
		}
		else{
			int i;
			for (i = 0; i<26; i++){
				if (Me[myPos - 'A'][i] + Prof[profPos - 'A'][i] == res){
					break;
				}
			}
			cout << res << ' ' << char(i + 'A') << endl;
		}
	}

	return 0;
}
