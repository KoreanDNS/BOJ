#include <bits/stdc++.h>
using namespace std;

const int MAX = 11;

int n, m;
char board[MAX][MAX];
bool vis[MAX][MAX][MAX][MAX];

using ti4 = tuple<int, int, int, int>;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int redY, redX, blueY, blueX;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			char what;
			cin >> what;
			board[y][x] = what;
			if ('R' == what)
			{
				redY = y;
				redX = x;
			}
			else if ('B' == what)
			{
				blueY = y;
				blueX = x;
			}
		}
	}

	queue<ti4> q;
	q.push({ redY, redX, blueY, blueX });
	vis[redY][redX][blueY][blueX] = true;

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };

	int ans = -1;

	int depth = 0;
	while (false == q.empty())
	{
		if (10 < ++depth)
		{
			break;
		}

		int size = q.size();
		while (size--)
		{
			auto cur = q.front();
			q.pop();

			int cRedY, cRedX, cBlueY, cBlueX;
			tie(cRedY, cRedX, cBlueY, cBlueX) = cur;

			for (int dir = 0; dir < 4; ++dir)
			{
				int nRedY = cRedY + dy[dir];
				int nRedX = cRedX + dx[dir];
				int nBlueY = cBlueY + dy[dir];
				int nBlueX = cBlueX + dx[dir];

				bool bRed = false;
				bool bBlue = false;
				while (1)
				{
					if ('O' == board[nRedY][nRedX])
					{
						bRed = true;
						break;
					}
					if ('#' == board[nRedY][nRedX])
					{
						break;
					}
					nRedY = nRedY + dy[dir];
					nRedX = nRedX + dx[dir];
				}
				nRedY = nRedY - dy[dir];
				nRedX = nRedX - dx[dir];

				while (1)
				{
					if ('O' == board[nBlueY][nBlueX])
					{
						bBlue = true;
						break;
					}
					if ('#' == board[nBlueY][nBlueX])
					{
						break;
					}
					nBlueY = nBlueY + dy[dir];
					nBlueX = nBlueX + dx[dir];
				}
				nBlueY = nBlueY - dy[dir];
				nBlueX = nBlueX - dx[dir];

				// 같은 위치에 있다면 거리 차이가 누가 더 큰지 판단하기
				if (nRedY == nBlueY and nRedX == nBlueX)
				{
					int red_dist = abs(nRedY - cRedY) + abs(nRedX - cRedX);
					int blue_dist = abs(nBlueY - cBlueY) + abs(nBlueX - cBlueX);
					if (red_dist < blue_dist)
					{
						nBlueY = nBlueY - dy[dir];
						nBlueX = nBlueX - dx[dir];
					}
					else
					{
						nRedY = nRedY - dy[dir];
						nRedX = nRedX - dx[dir];
					}
				}

				if (bBlue)
				{
					continue;
				}
				else if (bRed)
				{
					ans = depth;
					goto ANS_JUMP;
				}

				if (false == vis[nRedY][nRedX][nBlueY][nBlueX])
				{
					q.push({ nRedY, nRedX, nBlueY, nBlueX });
					vis[nRedY][nRedX][nBlueY][nBlueX] = true;
				}
			}
		}
	}

ANS_JUMP:
	cout << ans;
	return 0;
}