// Problem: HACKRNDM - Hacking the random number generator
// Link: https://www.spoj.com/problems/HACKRNDM/en/
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

#define MAX 10000

int main()
{
	int n, k, a;
	cin >> n >> k;
	vector<int> setNumber;
	int res = 0;
	for (int i = 0; i < n; i++){
		cin >> a;
		setNumber.push_back(a);
	}
	sort(setNumber.begin(), setNumber.end());
	for (int i = 0; i < n; i++){
		res += binary_search(setNumber.begin(), setNumber.end(), setNumber.at(i) - k);
	}
	cout << res << endl;

	return 0;
}