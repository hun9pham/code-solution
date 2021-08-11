// Problem: 10611 - The Playboy Chimp
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

#define MAX 10000

int arr[MAX];
int n, t, q;

int FindTallest(int q){//the tallest lady chimp that is shorter than Luchu
	int l = 0;
	int r = n - 1;
	int kq = 0;
	while (r >= l){
		int m = l + (r - l) / 2;
		if (arr[m] < q){
			kq = arr[m];
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	return kq;
}

int FindShortest(int q){//the shortest lady chimp that is taller than Luchu
	int l = 0;
	int r = n - 1;
	int kq = 0;
	while (r >= l){
		int m = l + (r - l) / 2;
		if (arr[m] > q){
			kq = arr[m];
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	return kq;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> q;
		int x = FindTallest(q);
		int y = FindShortest(q);
		if (x != 0){
			cout << x << ' ';
		}
		else cout << "X" << ' ';
		if (y != 0){
			cout << y;
		}
		else cout << "X";
		cout << endl;
	}

	return 0;
}