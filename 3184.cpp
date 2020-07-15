#include <bits/stdc++.h>
using namespace std;

const int MAX = 251;
char board[MAX][MAX];
bool vis[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int yidx=0; yidx<n; ++yidx)
	{
		cin >> board[yidx];
	}

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };

	int ans1 = 0;
	int ans2 = 0;
	for (int yidx=0; yidx<n; ++yidx)
	{
		for (int xidx=0; xidx<m; ++xidx)
		{
			if ('#' == board[yidx][xidx] or vis[yidx][xidx])
			{
				continue;
			}

			queue<pair<int, int>> q;
			q.push({ yidx, xidx });
			vis[yidx][xidx] = true;

			int tmpAns1 = 0;
			int tmpAns2 = 0;
			while (false == q.empty())
			{
				auto cur = q.front();
				q.pop();

				int cy = cur.first;
				int cx = cur.second;

				if ('o' == board[cy][cx])
				{
					++tmpAns1;
				}
				else if ('v' == board[cy][cx])
				{
					++tmpAns2;
				}

				for (int dir=0; dir<4; ++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];

					if (ny < 0 or n <= ny or nx < 0 or m <= nx)
					{
						continue;
					}

					if ('#' == board[ny][nx] or vis[ny][nx])
					{
						continue;
					}

					q.push({ ny, nx });
					vis[ny][nx] = true;
				}
			}

			if (tmpAns2 < tmpAns1)
			{
				ans1 += tmpAns1;
			}
			else
			{
				ans2 += tmpAns2;
			}
		}
	}

	cout << ans1 << ' ' << ans2;
	return 0;
}