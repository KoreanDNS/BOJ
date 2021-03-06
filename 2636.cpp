#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int board[MAX][MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	list<pair<int, int>> li;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cin >> board[y][x];
			if (1 == board[y][x])
			{
				li.push_back({ y, x });
			}
		}
	}

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };
	int ans = 0;
	int old = 0;
	while (false == li.empty())
	{
		list<list<pair<int, int>>::iterator> del;
		for (auto li_Iter = li.begin(); li_Iter != li.end(); ++li_Iter)
		{
			queue<pair<int, int>> q;
			q.push({ li_Iter->first, li_Iter->second });
			bool vis[MAX][MAX]{};
			vis[li_Iter->first][li_Iter->second] = true;

			while (false == q.empty())
			{
				auto cur = q.front();
				q.pop();
				li_Iter;
				int cy = cur.first;
				int cx = cur.second;

				if (0 == cy or n - 1 == cy or 0 == cx or m - 1 == cx)
				{
					del.push_back(li_Iter);
					break;
				}

				for (int dir = 0; dir < 4; ++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];

					if (ny < 0 or n <= ny or nx < 0 or m <= nx)
					{
						continue;
					}

					if (board[ny][nx] or vis[ny][nx])
					{
						continue;
					}

					q.push({ ny, nx });
					vis[ny][nx] = true;
				}
			}
		}

		old = del.size();
		for (auto cur : del)
		{
			board[cur->first][cur->second] = false;
			li.erase(cur);
		}
		++ans;
	}

	cout << ans << '\n';
	cout << old;

	return 0;
}
