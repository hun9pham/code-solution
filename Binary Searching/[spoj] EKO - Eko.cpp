// Problem: EKO - Eko
// Link: https://www.spoj.com/problems/EKO/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 10000050
#define INF 1e9
typedef pair<int, int> pii;
typedef long long int lli;

int main() {
	lli n, m, i;
	lli arr[MAX];
	cin >> n >> m;
	for (i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	lli left = 0;
	lli right = arr[n - 1];
	lli res = 0;
	while (left <= right){
		lli sum = 0;
		lli mid = (left + right) / 2;
		for (i = 0; i < n; i++){
			if (arr[i] > mid){
				sum += (arr[i] - mid);//cut off mid will gets sum
			}
		}
		if (sum < m){
			right = mid - 1;
		}
		else{
			left = mid + 1;
			res = mid;
		}
	}
	cout << res << endl;

	return 0;
}