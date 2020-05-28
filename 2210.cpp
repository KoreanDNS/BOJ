#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int board[5][5];

	for (int yidx = 0; yidx < 5; ++yidx)
	{
		for (int xidx = 0; xidx < 5; ++xidx)
		{
			cin >> board[yidx][xidx];
		}
	}

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };

	set<string> ans;
	for (int yidx = 0; yidx < 5; ++yidx)
	{
		for (int xidx = 0; xidx < 5; ++xidx)
		{
			queue<tuple<int, int, string>> q;
			q.push({ yidx, xidx, to_string(board[yidx][xidx]) });

			while (false == q.empty())
			{
				auto cur = q.front();
				q.pop();

				string& tmpV = get<2>(cur);
				if (6 == tmpV.length())
				{
					ans.insert(tmpV);
					continue;
				}

				int cy = get<0>(cur);
				int cx = get<1>(cur);

				for (int dir = 0; dir < 4; ++dir)
				{
					int ny = cy + dy[dir];
					int nx = cx + dx[dir];
					if (0 <= ny and ny < 5 and 0 <= nx and nx < 5)
					{
						q.push({ ny, nx, tmpV + to_string(board[ny][nx]) });
					}
				}
			}
		}
	}

	cout << ans.size();

	return 0;
}