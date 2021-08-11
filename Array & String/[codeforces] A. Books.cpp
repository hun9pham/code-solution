// Problem: A - Books
// Link: https://codeforces.com/problemset/problem/572/A
// Author: Pham Nguyen Quoc Hung

#include<bits/stdc++.h>

using namespace std;
#define MAX 100100

int main(){
	long int n1, n2;
	long int k, m;
	cin >> n1 >> n2;
	cin >> k >> m;
	long int a[n1], b[n2];
	for (long int i = 0; i < n1; i++){
		cin >> a[i];
	}
	for (long int i = 0; i < n2; i++){
		cin >> b[i];
	}
	if (b[n2 - m] > a[k - 1]){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}