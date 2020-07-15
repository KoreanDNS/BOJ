#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX = 21;
const int INF = numeric_limits<int>::max();

int board[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	// 초기 셋팅
	pair<int, int> start;
	for (int yidx = 0; yidx < n; ++yidx)
	{
		for (int xidx = 0; xidx < n; ++xidx)
		{
			cin >> board[yidx][xidx];
			if (9 == board[yidx][xidx]) // 아기 상어 위치 기억
			{
				start = { yidx, xidx };
			}
		}
	}

	int ans = 0;
	pair<int, int> nextP;

	int dy[4]{ -1, 1, 0, 0 };
	int dx[4]{ 0, 0, -1, 1 };
	int hp = 2;
	int count = 0;

	while (1)
	{
		queue<pair<int, int>> q;
		q.push(start);

		// vis[MAX][MAX][0]은 한번 방문한곳 다시 재 방문하지 않는 용도이고
		// vis[MAX][MAX][1]은 먹이를 먹을 수 있으면 최단 거리 비용

		int vis[MAX][MAX][2]{};
		vis[start.first][start.second][0] = 1;

		while (false == q.empty())
		{
			auto cur = q.front();
			q.pop();

			int cy = cur.first;
			int cx = cur.second;

			if (1 <= board[cy][cx] and board[cy][cx] <= 6)
			{
				if (board[cy][cx] < hp)
				{
					vis[cy][cx][1] = vis[cy][cx][0] - 1;
					continue;
				}
			}

			for (int dir = 0; dir<4; ++dir)
			{
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				if (ny < 0 or n <= ny or nx < 0 or n <= nx)
				{
					continue;
				}
				if (hp < board[ny][nx] or vis[ny][nx][0] or vis[ny][nx][1])
				{
					continue;
				}

				q.push({ ny, nx });
				vis[ny][nx][0] = vis[cy][cx][0] + 1;
			}
		}

		int check = INF;
		for (int yidx = 0; yidx<n; ++yidx)
		{
			for (int xidx = 0; xidx<n; ++xidx)
			{
				int what = vis[yidx][xidx][1];
				if (0 != what)
				{
					if (what < check)
					{
						check = what;
						nextP = { yidx, xidx };
					}
				}
			}
		}

		if (INF == check) // 더 이상 먹이를 찾을 수 없다면 빠져 나가야 함
		{
			break;
		}
		else
		{
			// 좌표 값, 결과 값, 상어 크기 갱신
			ans += check;
			board[start.first][start.second] = 0;
			board[nextP.first][nextP.second] = 9;
			if (hp == ++count)
			{
				count = 0;
				++hp;
			}

			start = nextP;
		}
	}

	cout << ans;

	return 0;
}