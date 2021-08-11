// Problem: 10583 - Ubiquitous Religions
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1524
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX 50050

int n, m;
int a, b;
int arr[MAX];

int main() {
	static int tc = 1;
	while (cin >> n >> m){
		if (!n && !m) break;
		for (int i = 1; i <= n; i++){
			arr[i] = i;
		}
		for (int i = 0; i < m; i++){
			cin >> a >> b;
			while (a != arr[a]){
				a = arr[a];
			}
			while (b != arr[b]){
				b = arr[b];
			}
			if (a != b){
				n--;
				arr[b] = a;
			}
		}
		printf("Case %d: %d\n", tc++, n);
	}
	return 0;
}