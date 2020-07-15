#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
char board[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<m; ++j)
		{
			cin >> board[i][j];
		}
	}

	int ans = 1;
	for (int yidx=0; yidx<n; ++yidx)
	{
		for (int xidx=0; xidx<m; ++xidx)
		{
			char what = board[yidx][xidx];
			if ('-' == what)
			{
				for (int cur=xidx; cur<m; ++cur)
				{
					if (what != board[yidx][cur])
					{
						break;
					}
					board[yidx][cur] = 0;
				}
			}
			else if ('|' == what)
			{
				for (int cur=yidx; cur<n; ++cur)
				{
					if (what != board[cur][xidx])
					{
						break;
					}
					board[cur][xidx] = 0;
				}
			}
			else
			{
				continue;
			}
			ans++;
		}
	}

	cout << ans - 1;

	return 0;
}