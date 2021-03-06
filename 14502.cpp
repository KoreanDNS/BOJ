#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;
int board[MAX][MAX];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	int maxZero = 0;
	vector<pair<int, int>> startVirus;
	for (int yidx = 0; yidx < n; ++yidx)
	{
		for (int xidx = 0; xidx < m; ++xidx)
		{
			int what;
			cin >> what;
			board[yidx][xidx] = what;
			if (0 == what)
			{
				++maxZero;
			}
			else if (2 == what)
			{
				startVirus.push_back({ yidx, xidx });
			}
		}
	}

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };

	int ans = 0;
	const int dst = n * m;
	for (int yidx = 0; yidx < dst - 2; ++yidx)
	{
		if (board[yidx / m][yidx % m])
		{
			continue;
		}

		for (int xidx = yidx + 1; xidx < dst - 1; ++xidx)
		{
			if (board[xidx / m][xidx % m])
			{
				continue;
			}

			for (int zidx = xidx + 1; zidx < dst; ++zidx)
			{
				int tmpBoard[MAX][MAX];
				memcpy(tmpBoard, board, sizeof(board));				
				
				if (board[zidx / m][zidx % m])
				{
					continue;
				}

				tmpBoard[yidx / m][yidx % m] = 1;
				tmpBoard[xidx / m][xidx % m] = 1;
				tmpBoard[zidx / m][zidx % m] = 1;
				int tmpZero = maxZero - 3;

				queue<pair<int, int>> q({ startVirus.begin(), startVirus.end() });
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

						if (ny < 0 or n <= ny or nx < 0 or m <= nx)
						{
							continue;
						}
						if (tmpBoard[ny][nx])
						{
							continue;
						}

						--tmpZero;
						tmpBoard[ny][nx] = 2;
						q.push({ny, nx});
					}
				}

				ans = max(ans, tmpZero);
			}
		}
	}

	cout << ans;

	return 0;
}
