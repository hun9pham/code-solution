// Problem: Finding Square Roots
// Link: https://www.codechef.com/problems/FSQRT
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define MAX 2005
#define INF 1e9

int main() {
	int n, t;
	cin >> t;
	while (t--){
		cin >> n;
		double l = 0;
		double r = double(n);
		double m = 0;
		while (r > l){
			m = (r + l) / 2;
			double Square = m*m;
			if (Square < double(n)){
				l = m + 1e-8;
			}
			else{
				r = m - 1e-8;
			}
		}
		cout << int(round(m)) << endl;
	}
	system("pause");
	return 0;
}