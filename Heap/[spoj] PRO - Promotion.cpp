// Problem: PRO - Promotion
// Link: https://www.spoj.com/problems/PRO/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n;
	long long int a, k;
	long long int total = 0;
	multiset<int> s;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> k;
		for (long long int j = 0; j < k; j++){
			if (k == 0) break;
			cin >> a;
			s.insert(a);
		}
		if (s.size() > 1){
			multiset<int>::iterator front = s.begin();
			multiset<int>::iterator back = s.end();
			back--;
			total += (*back - *front);
			s.erase(front);
			s.erase(back);
		}
	}
	cout << total << endl;
	return 0;
}