// Problem: Compilers and parsers
// Link: https://www.codechef.com/problems/COMPILER
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string s;
	vector<string> vs;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		vs.push_back(s);
	}
	for (int i = 0; i < n; i++){
		int cnt = 0;
		int res = 0;
		int k = 0;
		for (int j = 0; j < vs.at(i).length(); j++){
			char c = vs.at(i)[j];
			if (c == '<'){
				k++;
			}
			else{
				k--;
				if (k < 0) break;
				cnt++;
				if (k == 0){
					res = cnt;
				}

			}
		}
		cout << res * 2 << endl;
	}
	return 0;
}