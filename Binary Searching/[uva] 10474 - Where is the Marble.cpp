// Problem: 10474 - Where is the Marble?
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

#define MAX 10000

int BinarySearch(vector<int> marbles, int n) {
	auto it = lower_bound(marbles.begin(), marbles.end(), n);
	if (it == marbles.end() || (*it) != n) {
		return -1;
	}
	else {
		int index = distance(marbles.begin(), it);
		return index;
	}
}

int main() {
	int N, Q;
	int n;
	int q;
	while (cin >> N >> Q){
		if (N == 0 && Q == 0) break;
		vector<int> marbles;
		vector<int> queries;
		static int Case = 1;
		for (int i = 0; i < N; i++){
			int n;
			cin >> n;
			marbles.push_back(n);
		}
		sort(marbles.begin(), marbles.end());
		for (int i = 0; i < Q; i++){
			cin >> q;
			queries.push_back(q);
		}
		printf("CASE# %d:\n", Case++);
		for (int i = 0; i < Q; i++){
			int index = BinarySearch(marbles, queries[i]);
			if (index == -1){
				printf("%d not found\n", queries[i]);
			}
			else{
				printf("%d found at %d\n", queries[i], index + 1);
			}
		}

	}

	return 0;
}