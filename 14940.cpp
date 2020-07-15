#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int board[MAX][MAX];
int vis[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	pair<int, int> start;
	for (int yidx=0; yidx<n; ++yidx)
	{
		for (int xidx=0; xidx<m; ++xidx)
		{
			int what;
			cin >> what;
			board[yidx][xidx] = what;
			if (2 == what)
			{
				start = { yidx, xidx };
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(start);
	vis[start.first][start.second] = 1;

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };
	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		int cy = cur.first;
		int cx = cur.second;

		for (int dir=0; dir<4; ++dir)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 or MAX <= ny or nx < 0 or MAX <= nx)
			{
				continue;
			}
			if (0 == board[ny][nx] or vis[ny][nx])
			{
				continue;
			}

			board[ny][nx] = 3;
			q.push({ ny, nx });
			vis[ny][nx] = vis[cy][cx] + 1;
		}
	}

	for (int yidx = 0; yidx < n; ++yidx)
	{
		for (int xidx = 0; xidx < m; ++xidx)
		{
			if (1 == board[yidx][xidx])
			{
				cout << -1 << ' ';
			}
			else
			{
				int what = vis[yidx][xidx] - 1;
				if (what < 0)
				{
					what = 0;
				}
				cout << what << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}