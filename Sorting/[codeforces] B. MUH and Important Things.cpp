// Problem: B. MUH and Important Things
// Link: https://codeforces.com/problemset/problem/471/B
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

#define MAX 2005

struct Task{
	int index;
	int diff;
};
int n, h;
Task task[MAX];
vector<Task> v[MAX];

bool cmp(Task a, Task b){
	return a.diff < b.diff;
}
void IN(){
	for (int i = 1; i <= n; i++){
		cout << task[i].index << ' ';
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> task[i].diff;
		task[i].index = i;
	}
	sort(task + 1, task + n + 1, cmp);
	int cnt = 0;
	for (int i = 2; i <= n; i++){
		if (task[i].diff == task[i - 1].diff){
			cnt++;
		}
	}
	if (cnt >= 2){
		cout << "YES" << endl;
		for (int i = 0; i < 3; i++){
			bool flag = false;
			for (int j = 1; j <= n; j++){
				cout << task[j].index;
				if (j == n) cout << endl;
				else cout << ' ';
				if (flag == false && j != 1 && task[j].diff == task[j - 1].diff && task[j].index > task[j - 1].index){
					swap(task[j], task[j - 1]);
					flag = true;
				}
			}
		}
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}