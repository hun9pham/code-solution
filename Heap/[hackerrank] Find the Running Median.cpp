// Problem: Find the Running Median
// Link: https://vjudge.net/problem/UVA-11995
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<float> result;
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	while (n--){
		int num;
		cin >> num;
		int total = 0;
		if (maxHeap.empty()){
			maxHeap.push(num);
		}
		else{
			if (maxHeap.top() > num){
				maxHeap.push(num);
			}
			else{
				minHeap.push(num);
			}
		}
		while (minHeap.size() > maxHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		while (maxHeap.size() - minHeap.size() > 1){
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		total = maxHeap.size() + minHeap.size();
		if (total % 2 == 0){
			float res1 = float(maxHeap.top());
			float res2 = float(minHeap.top());
			float res = (res1 + res2) / 2;
			result.push_back(res);
		}
		else{
			float res = float(maxHeap.top());
			result.push_back(res);
		}
	}
	for (auto it : result){
		printf("%0.1f\n", it);
	}
	return 0;
}