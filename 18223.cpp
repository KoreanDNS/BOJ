#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
const int INF = numeric_limits<int>::max();

vector<vector<pii>> adj;
int v, e;

vector<ll> dijkstra(const int start)
{
	vector<ll> vis(v + 1, INF);
	vis[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, start});

	while (false == pq.empty())
	{
		const auto cur = pq.top();
		pq.pop();

		const int dist = cur.first;
		const int idx = cur.second;

		if (dist != vis[idx])
		{
			continue;
		}

		for (const auto next : adj[idx])
		{
			const int cost = next.first;
			const int nidx = next.second;
			if (cost + dist < vis[nidx])
			{
				vis[nidx] = cost + dist;
				pq.push({ vis[nidx], nidx });
			}
		}
	}

	return vis;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int target;
	cin >> v >> e >> target;

	adj.resize(v + 1);

	for (int idx = 0; idx < e; ++idx)
	{
		int from, to, w;
		cin >> from >> to >> w;
		adj[from].push_back({ w, to });
		adj[to].push_back({ w, from });
	}

	const auto root = dijkstra(1);
	const auto targetNode = dijkstra(target);

	cout << (root[target] + targetNode[v] <= root[v] ? "SAVE HIM" : "GOOD BYE");

	return 0;
}