// Problem: OPCPIZZA - Pizzamania
// Link: https://www.spoj.com/problems/OPCPIZZA/en/
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

#define MAX 10000

int arr[MAX];
int cnt = 0;
int n, m;

void BinarySearch(int l, int r, int num){
	if (r > l){
		int temp = arr[l] + arr[r];
		if (temp == num){
			cnt++;
			BinarySearch(l + 1, r - 1, num);
		}
		else if (temp < num){
			BinarySearch(l + 1, r, num);
		}
		else BinarySearch(l, r - 1, num);
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			int b;
			cin >> b;
			arr[i] = b;
		}
		cnt = 0;
		sort(arr, arr + n);
		BinarySearch(0, n - 1, m);
		cout << cnt << endl;
	}

	return 0;
}