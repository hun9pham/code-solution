// Problem: 12032 - The Monkey and the Oiled Bamboo
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

#define MAX 10000

int main() {
	int t;
	int n;
	static int Case = 1;
	cin >> t;
	while (t--){
		cin >> n;
		vector<int> v;
		vector<int> d;
		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			v.push_back(a);
		}
		d.push_back(v[0]);
		if (n == 1){
			printf("Case %d: %d\n", Case++, v[0]);
			continue;
		}
		for (int i = 1; i < n; i++){
			int k = v.at(i) - v.at(i - 1);
			d.push_back(k);
		}
		int k = *max_element(d.begin(), d.end());
		int temp = *max_element(d.begin(), d.end());
		bool flag = false;
		for (int i = 0; i < n; i++){
			if (temp == d[i]){
				temp--;
			}
			else if (temp < d[i]){
				flag = true;
				break;
			}
		}
		if (flag == true){
			k++;
		}
		printf("Case %d: %d\n", Case++, k);

	}

	return 0;
}