// Problem: F - Passwords 
// Link: https://codeforces.com/problemset/problem/721/B
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(string a, string b){
	return a.length() > b.length();
}

int main(){
	int n, k;
	int t_min = 1, t_max = 1;
	int test_min = 0;
	int test_max = 0;
	cin >> n >> k;
	string s[n];
	string password;
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	cin >> password;
	sort(s, s + n, cmp);
	for (int i = 0; i< n; i++){
		if (s[i].length() < password.length()){
			t_min++;
			t_max++;
			test_min++;
			test_max++;
		}
		else if (s[i].length() == password.length()){
			if (s[i] != password){
				t_max++;
				test_max++;
			}
		}
	}
	int res1 = (test_min / k) * 5;
	int res2 = (test_max / k) * 5;
	cout << t_min + res1 << ' ' << t_max + res2 << endl;

	return 0;
}