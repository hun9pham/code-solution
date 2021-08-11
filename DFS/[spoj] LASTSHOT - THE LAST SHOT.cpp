// Problem: LASTSHOT - THE LAST SHOT
// Link: https://www.spoj.com/problems/LASTSHOT/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 10100
typedef long long int ll;

bool seen[MAX];
int N, M;
vector<int> bomb[MAX];
int path[MAX];

int dfs(int root){
	int cnt = 0;
	stack<int> st;
	st.push(root);
	seen[root] = true;
	while (!st.empty()){
		int t = st.top();
		st.pop();
		cnt++;
		//cout << "t = " << t << endl;
		//cout << "cnt= " << cnt << endl;
		for (int i = 0; i < bomb[t].size(); i++){
			int k = bomb[t][i];
			//cout << "k = " << k << endl;
			if (seen[k] == false){
				st.push(k);
				seen[k] = true;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int A, B;
		cin >> A >> B;
		bomb[A].push_back(B);
	}
	vector<int> MAX_IMPACT;
	for (int i = 1; i <= N; i++){
		memset(seen, false, sizeof(seen));
		int k = dfs(i);
		MAX_IMPACT.push_back(k);
	}
	cout << *max_element(MAX_IMPACT.begin(), MAX_IMPACT.end()) << endl;
	return 0;
}