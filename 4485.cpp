#include <bits/stdc++.h>
using namespace std;

using tii = tuple<int, int, int>;
const int INF = numeric_limits<int>::max();
const int MAX = 125 + 1;

int board[MAX][MAX];
int vis[MAX][MAX];

int n;

int dijkstra()
{
	int ans = 0;

	for (int idx=0; idx<MAX; ++idx)
	{
		fill(vis[idx], vis[idx] + MAX, INF);
	}

	priority_queue<tii, vector<tii>, greater<tii>> pq;
	pq.push({board[0][0], 0, 0});

	vis[0][0] = board[0][0];

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };
	while (false == pq.empty())
	{
		const auto cur = pq.top();
		pq.pop();

		int dist, cy, cx;
		tie(dist, cy, cx) = cur;

		if (dist != vis[cy][cx])
		{
			continue;
		}

		for (int dir=0; dir<4; ++dir)
		{
			const int ny = cy + dy[dir];
			const int nx = cx + dx[dir];
			const int cost = board[ny][nx];

			if (ny < 0 or n <= ny or nx < 0 or n <= nx)
			{
				continue;
			}

			if (cost + dist < vis[ny][nx])
			{
				vis[ny][nx] = cost + dist;
				pq.push({ vis[ny][nx], ny, nx });
			}
		}
	}

	return vis[n-1][n-1];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int idx=1;;++idx)
	{
		cin >> n;
		if (0 == n)
		{
			break;
		}

		for (int yidx = 0; yidx < n; ++yidx)
		{
			for (int xidx = 0; xidx < n; ++xidx)
			{
				cin >> board[yidx][xidx];
			}
		}

		cout << "Problem " << idx << ": " << dijkstra() << '\n';
	}

	return 0;
}