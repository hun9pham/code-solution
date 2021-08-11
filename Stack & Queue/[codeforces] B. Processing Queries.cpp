// Problem: Processing Queries
// Link: https://codeforces.com/problemset/problem/644/B
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long int li;

int main()
{
	li n;
	li b;
	li t, d;
	li time;
	cin >> n >> b;
	bool flag = true;
	queue<li> qInput;
	queue<li> qOutput;
	for (li i = 0; i < n; i++){
		cin >> t >> d;
		if (flag == true){
			time = t + d;
			qInput.push(time);
			qOutput.push(time);
			flag = false;
		}
		else{
			while (qInput.size() > 0 && t >= qInput.front()){
				qInput.pop();
			}
			if (t <= time){
				if (qInput.size() > b){
					qOutput.push(-1);
				}
				else{
					time += d;
					qInput.push(time);
					qOutput.push(time);
				}
			}
			else{
				time = t + d;
				qInput.push(time);
				qOutput.push(time);
			}
		}
	}
	while (!qOutput.empty()){
		cout << qOutput.front() << ' ';
		qOutput.pop();
	}
	return 0;
}