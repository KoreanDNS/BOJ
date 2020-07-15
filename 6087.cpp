#include <bits/stdc++.h>
using namespace std;

using ti4 = tuple<int, int, int, int>;

const int INF = numeric_limits<int>::max();
const int MAX = 101;
string board[MAX];
int vis[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	ti4 start;
	pair<int, int> end;

	bool startCheck = true;

	for (int yidx = 0; yidx < n; ++yidx)
	{
		for (int xidx = 0; xidx < m; ++xidx)
		{
			char what;
			cin >> what;
			board[yidx] += what;
			if ('C' == what)
			{
				if (startCheck)
				{
					start = { yidx, xidx, -1, 0 };
				}
				else
				{
					end = { yidx, xidx };
				}
				startCheck = false;
			}
			vis[yidx][xidx] = INF;
		}
	}

	queue<ti4> q;
	q.push(start);

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };

	while (false == q.empty())
	{
		auto cur = q.front();
		q.pop();

		int cy, cx, cdir, cCost;
		tie(cy, cx, cdir, cCost) = cur;

		for (int dir = 0; dir < 4; ++dir)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 or n <= ny or nx < 0 or m <= nx)
			{
				continue;
			}

			if ('*' == board[ny][nx])
			{
				continue;
			}

			int nCost = cCost;
			if (cdir != dir)
			{
				++nCost;
			}

			if (nCost <= vis[ny][nx])
			{
				vis[ny][nx] = nCost;
				q.push({ ny, nx, dir, nCost });
			}
		}
	}

	cout << vis[end.first][end.second] - 1;

	return 0;
}