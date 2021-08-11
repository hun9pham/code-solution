// Problem: STPAR - Street Parade
// Link: https://www.spoj.com/problems/STPAR/en/
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main()
{
	int n;
	while (1) {
		cin >> n;
        int a[n];
        queue<int> q;
        stack<int> s1;
        stack<int> s2;
		if (n == 0) break;
		for(int i = 0; i < n; i++){
            cin >> a[i];
            q.push(a[i]);
        }
        int cnt = 1;
        for(int i = 0; i < n; i++){
            while(s1.size() != 0 && s1.top() == cnt){
                s2.push(s1.top());
                s1.pop();
                cnt++;
            }
            if(q.front() != cnt){
                s1.push(q.front());
                q.pop();
            }
            else{
                s2.push(q.front());
                q.pop();
                cnt++;
            }
        }
        //cout << cnt << endl;
        while(s1.size() != 0 && s1.top() == cnt){
            s2.push(s1.top());
            s1.pop();
            cnt++;
        }
        sort(a, a + n, cmp);
        bool flag =  true;
        for(int i = 0; i < n; i++){
            if(a[i] != s2.top()){
                flag = false;
                break;
            }
            s2.pop();
        }
        if(flag){
            cout << "yes" << endl;
        }
        else cout << "no" << endl;
	}
	return 0;
}