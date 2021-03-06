#include <bits/stdc++.h>
using namespace std;

using ti3 = tuple<int, int, int>;

const int MAX = 51;
int board[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int robotY;
	int robotX;
	int robotDir;
	cin >> robotY >> robotX >> robotDir;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			cin >> board[y][x];
		}
	}

	stack<ti3> s;
	s.push({ robotY, robotX, robotDir });

	int dy[4]{ -1, 0, 1, 0 };
	int dx[4]{ 0, 1, 0, -1 };

	int ans = 0;
	while (false == s.empty())
	{
		auto cur = s.top();
		s.pop();

		int cy, cx, cdir;
		tie(cy, cx, cdir) = cur;

		// 1. 현재 위치 청소를 한다.
		if (0 == board[cy][cx])
		{
			board[cy][cx] = 7;
			++ans;
		}

		int i = 0;
		int ndir = cdir;
		for (; i < 4; ++i)
		{
			// 2. 현재 방향에서 왼쪽 방향으로 회전 한 다음
			switch (ndir)
			{
			case 0: // 북
				ndir = 3;
				break;
			case 1: // 동
				ndir = 0;
				break;
			case 2: // 남
				ndir = 1;
				break;
			case 3: // 서
				ndir = 2;
				break;
			default:
				break;
			}

			// 한칸 전진 할 수 있는지 체크
			int ny = cy + dy[ndir];
			int nx = cx + dx[ndir];

			if (ny < 0 or n <= ny or nx < 0 or m <= nx)
			{
				continue;
			}

			if (0 == board[ny][nx])
			{
				s.push({ ny, nx, ndir });
				break;
			}
		}

		// 네 방향 모두 청소가 되어 있다.
		if (4 == i)
		{
			// 뒤로 후진 할 수 있는지 조건 판단
			int ndir;
			switch (cdir)
			{
			case 0: // 북
				ndir = 2;
				break;
			case 1: // 동
				ndir = 3;
				break;
			case 2: // 남
				ndir = 0;
				break;
			case 3: // 서
				ndir = 1;
				break;
			default:
				break;
			}

			// 한칸 전진 할 수 있는지 체크
			int ny = cy + dy[ndir];
			int nx = cx + dx[ndir];

			if (ny < 0 or n <= ny or nx < 0 or m <= nx)
			{
				continue;
			}

			if (1 != board[ny][nx])
			{
				s.push({ ny, nx, cdir });
			}
		}
	}

	cout << ans;

	return 0;
}