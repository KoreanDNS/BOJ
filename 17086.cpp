#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;

int board[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int yidx=0; yidx<n; ++yidx)
	{
		for (int xidx=0; xidx<m; ++xidx)
		{
			cin >> board[yidx][xidx];
		}
	}

	int dy[8]{ -1, 1, 0, 0, -1, -1, 1, 1 };
	int dx[8]{ 0, 0, -1, 1, -1, 1, -1, 1 };

	int ans = 0;
	for (int yidx = 0; yidx < n; ++yidx)
	{
		for (int xidx = 0; xidx < m; ++xidx)
		{
			queue<pair<int, int>> q;
			q.push({yidx, xidx});

			int vis[MAX][MAX]{ 0 };
			vis[yidx][xidx] = 1;

			int minV = 0;
			while (false == q.empty())
			{
				auto cur = q.front();
				q.pop();

				int cy = cur.first;
				int cx = cur.second;

				for (int dir=0; dir<8; ++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];

					if (ny < 0 or n <= ny or nx < 0 or m <= nx)
					{
						continue;
					}
					if (vis[ny][nx])
					{
						continue;
					}

					if (1 == board[ny][nx])
					{
						minV = vis[cy][cx];
						if (1 == board[yidx][xidx])
						{
							--minV;
						}
						goto JUMP;
					}
					
					vis[ny][nx] = vis[cy][cx] + 1;
					q.push({ ny, nx });
				}
			}
		JUMP:
			ans = max(ans, minV);
		}
	}

	cout << ans;

	return 0;
}