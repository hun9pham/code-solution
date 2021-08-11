// Problem: C. Heap Operations
// Link: https://codeforces.com/problemset/problem/681/C
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <string>
using namespace std;

typedef long long ll;

typedef struct Command{
	string s;
	ll num;
}Command;

int main() {
	int n;
	cin >> n;
	priority_queue<ll> pq;
	vector<Command> output;
	ll num;
	while (n--){
		string cmd;
		cin >> cmd;
		if (cmd == "insert"){
			cin >> num;
			pq.push((-1)*num);
			Command cm = { cmd, num };
			output.push_back(cm);
		}
		else if (cmd == "getMin"){
			cin >> num;
			if (!pq.empty()){
				while (pq.size() && ((-1)*pq.top()) < num){
					pq.pop();
					Command cm = { "removeMin", -1 };
					output.push_back(cm);
				}
				if (pq.size() == 0 || (-1)*pq.top() > num){
					pq.push((-1)*num);
					Command cm = { "insert", num };
					output.push_back(cm);
				}
				Command cm = { "getMin", num };
				output.push_back(cm);
			}
			else{
				pq.push((-1)*num);
				Command cm1 = { "insert", num };
				Command cm2 = { "getMin", num };
				output.push_back(cm1);
				output.push_back(cm2);
			}
		}
		else{
			if (pq.size() == 0){
				Command cm = { "insert", 0 };
				output.push_back(cm);
			}
			else{
				pq.pop();
			}
			Command cm = { cmd, -1 };
			output.push_back(cm);
		}
	}
	cout << output.size() << endl;
	for (vector<Command>::iterator it = output.begin(); it != output.end(); it++){
		if ((*it).s == "removeMin"){
			cout << "removeMin" << endl;
		}
		else{
			cout << (*it).s << ' ' << (*it).num << endl;
		}
	}
	return 0;
}