#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> v;

	vector<vector<int>> adj(v+1);

	int node1, node2;
	cin >> node1 >> node2;

	int e;
	cin >> e;

	for (int idx=0; idx<e; ++idx)
	{
		int from, to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	queue<int> q;
	q.push(node1);

	int vis[101]{ 0 };
	vis[node1] = 1;

	int parent[101];
	fill(parent, parent + 101, -1);
	parent[node1] = 1;

	while (false == q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : adj[cur])
		{
			if (false == vis[next])
			{
				q.push(next);
				vis[next] = vis[cur] + 1;
				parent[next] = cur;
			}
		}
	}

    cout << (-1 == parent[node2] ? -1 : vis[node2] - 1);

	return 0;
}