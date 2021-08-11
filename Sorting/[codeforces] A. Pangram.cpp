// Problem: C - Bear and Game
// Link: https://codeforces.com/problemset/problem/673/A
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string s;
	int n;
	bool flag = true;
	int cnt = 1;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] + 32;
		}
	}
	sort(s.begin(), s.end());
	for (int i = 0; i < n - 1; i++){
		if (s[i] != s[i + 1]){
			cnt++;
		}
	}
	if (cnt == 26) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}