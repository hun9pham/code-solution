// Problem: D - Night at the Museum
// Link: https://codeforces.com/problemset/problem/731/A
// Author: Pham Nguyen Quoc Hung

#include<bits/stdc++.h>

using namespace std;
#define MAX 100100

struct Node
{
	char data;
	struct Node *next;
	struct Node *prev;
};
void insertEnd(struct Node** start, char value)
{
	if (*start == NULL)
	{
		struct Node* new_node = new Node;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}
	Node *last = (*start)->prev;
	struct Node* new_node = new Node;
	new_node->data = value;
	new_node->next = *start;
	(*start)->prev = new_node;
	new_node->prev = last;
	last->next = new_node;
}

void display(struct Node* start)
{
	struct Node *temp = start;
	while (temp->next != start)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << temp->data << endl;
}

int main(){
	int kq = 0;
	int l = 0, r = 0;
	struct Node * head = NULL;
	for (char i = 'a'; i <= 'z'; i++)
		insertEnd(&head, i);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		l = 0;
		r = 0;
		Node * pos = head;
		while (head->data != s[i]){
			r++;
			head = head->next;
		}
		head = pos;
		while (head->data != s[i]){
			l++;
			head = head->prev;
		}
		kq += min(l, r);
	}
	cout << kq << endl;
	return 0;
}