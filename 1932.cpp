#include <bits/stdc++.h>
using namespace std;

const int MAX = 500;
int board[MAX][MAX];
int vis[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int yidx=0; yidx<n; ++yidx)
	{
		for (int xidx=0; xidx<=yidx; ++xidx)
		{
			cin >> board[yidx][xidx];
		}
	}

	vis[0][0] = board[0][0];
	queue<pair<int, int>> q;
	q.push({0, 0});

	int dy[2]{ 1, 1 };
	int dx[2]{ 0, 1 };
	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		int cy = cur.first;
		int cx = cur.second;

		for (int dir=0; dir<2; ++dir)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if (ny < 0 or n <= ny or nx < 0 or n <= nx)
			{
				continue;
			}

			if (vis[ny][nx] < vis[cy][cx] + board[ny][nx])
			{
				vis[ny][nx] = vis[cy][cx] + board[ny][nx];
				q.push({ ny, nx });
			}
		}

	}

	cout << *max_element(vis[n - 1], vis[n-1]+n);
	return 0;
}