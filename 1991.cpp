#include <bits/stdc++.h>
using namespace std;

vector <vector<pair<char, char>>> adj;

void preorder(char cur)
{
	for (auto next : adj[cur - 'A'])
	{
		char left = next.first;
		char right = next.second;
		cout << cur;
		if ('.' != left)
		{
			preorder(left);
		}
		if ('.' != right)
		{
			preorder(right);
		}
	}
}

void inorder(char cur)
{
	for (auto next : adj[cur - 'A'])
	{
		char left = next.first;
		char right = next.second;
		if ('.' != left)
		{
			inorder(left);
		}
		cout << cur;
		if ('.' != right)
		{
			inorder(right);
		}
	}
}

void postorder(char cur)
{
	for (auto next : adj[cur - 'A'])
	{
		char left = next.first;
		char right = next.second;
		if ('.' != left)
		{
			postorder(left);
		}
		if ('.' != right)
		{
			postorder(right);
		}
		cout << cur;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	adj.resize(n);
	for (int idx = 1; idx <= n; ++idx)
	{
		char p, l, r;
		cin >> p >> l >> r;

		adj[p - 'A'].push_back({ l, r });
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}