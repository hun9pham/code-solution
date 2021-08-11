// Problem: QHEAP1
// Link: https://vjudge.net/problem/HackerRank-qheap1
// Author: Pham Nguyen Quoc Hung

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

deque<int> heap;

void add(int v)
{
	if (heap.empty())
		heap.push_back(v);
	else
	{
		auto it = heap.begin();
		while (it != heap.end())
		{
			if (v > (*it))
				it++;
			else
			{
				heap.insert(it, v);
				break;
			}
			if (it == heap.end())
				heap.insert(it, v);
		}
	}
}

void del(int v)
{
	for (auto it = heap.begin(); it != heap.end(); ++it)
	{
		if ((*it) == v)
		{
			heap.erase(it);
			break;
		}
	}
}

int main() {
	int Q;
	cin >> Q;
	while (Q--)
	{
		int p, v;
		cin >> p;
		switch (p)
		{
		case 1:
			cin >> v;
			add(v);
			break;
		case 2:
			cin >> v;
			del(v);
			break;
		case 3:
			cout << heap.front() << endl;
			break;
		}
	}
	return 0;
}