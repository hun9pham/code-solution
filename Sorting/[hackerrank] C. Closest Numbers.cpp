// Problem: C - Closest Numbers
// Link: https://www.hackerrank.com/contests/interfacecse-codedash/challenges/closest-numbers
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int* closestNumbers(int arr_count, int* arr) {
	int * new_arr = (int*)malloc(sizeof(int)* 1000);
	sort(arr, arr + arr_count);
	int temp1 = arr[1] - arr[0];
	int temp2;
	int cnt = 0;
	for (int i = 1; i < arr_count; i++){
		temp2 = arr[i] - arr[i - 1];
		if (temp2 == temp1){
			new_arr[cnt] = arr[i - 1];
			cnt++;
			new_arr[cnt] = arr[i];
			cnt++;
		}
		else if (temp2 < temp1){
			temp1 = arr[i] - arr[i - 1];
			cnt = 0;
			new_arr[cnt] = arr[i - 1];
			cnt++;
			new_arr[cnt] = arr[i];
			cnt++;
		}
	}
	return new_arr;
}

int main(){
	int n;
	cin >> n;
	int arr[200050];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int * p = closestNumbers(n, arr);
	while (*p != 0){
		cout << *p << ' ';
		p++;
	}

	return 0;
}