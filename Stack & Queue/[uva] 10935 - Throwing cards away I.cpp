// Problem: 10935 - Throwing cards away I
// Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876
// Author: Pham Nguyen Quoc Hung

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	queue<int> q;
	while (1){
		cin >> n;
		if (n == 0) break;
		else if (n == 1){
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: 1" << endl;
		}
		else{
			for (int i = 1; i <= n; i++) {
				q.push(i);
			}

			cout << "Discarded cards:";
			while (q.size() > 1) {
				cout << ' ' << q.front();
				q.pop();
				int x = q.front();
				q.pop();
				if (!q.empty())
					printf(",");
				q.push(x);
			}
			cout << "\nRemaining card: " << q.front() << endl;
			q.pop();
		}
	}

	return 0;
}