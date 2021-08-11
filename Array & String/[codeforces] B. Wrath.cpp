// Problem: B - Wrath
// Link: https://codeforces.com/problemset/problem/892/B
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[1000010];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int j = n;
	int cnt = 0;
	for (int i = j - 1; i >= 0; i--){
		if (j > i){
			cnt++;
		}
		int k = i - arr[i];
		if (j  > k){
			j = k;
		}
	}
	cout << cnt << endl;

	return 0;
}