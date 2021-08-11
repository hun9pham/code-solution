// Problem: Restaurant Rating 
// Link: https://www.codechef.com/problems/RRATING
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<long long, vector<long long>, greater<long long>> min_heap;
	priority_queue<long long> max_heap;
	int numOfRate = 0;
	while (n--) {
		int a;
		cin >> a;
		if (a == 1) {
			long long rate;
			cin >> rate;
			if (max_heap.size() && rate < max_heap.top()) {
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(rate);
				numOfRate++;
			}
			else{
				min_heap.push(rate);
				numOfRate++;
			}
		}
		else {
			if (numOfRate < 3)
				cout << "No reviews yet";
			else {
				int k = numOfRate / 3;
				while (min_heap.size() > k) {
					max_heap.push(min_heap.top());
					min_heap.pop();
				}
				cout << min_heap.top();
			}
			cout << "\n";
		}
	}
}