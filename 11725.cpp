#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <vector<int>> adj(n+1);
    
	for (int idx = 1; idx < n; ++idx)
	{
		int from, to;
		cin >> from >> to;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	queue<int> q;
	q.push(1);

	vector<int> vis(n + 1);
	vis[1] = 1;

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (auto next : adj[cur])
		{
			if (false == vis[next])
			{
				q.push(next);
				vis[next] = cur;
			}
		}
	}

	for (int idx = 2; idx <= n; ++idx)
	{
		cout << vis[idx] << '\n';;
	}

	return 0;
}