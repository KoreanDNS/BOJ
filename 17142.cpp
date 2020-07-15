#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
int board[MAX][MAX];

int n, m;
vector<pair<int, int>> v;
pair<int, int> tmpV[10];
int boardZero;

priority_queue<int, vector<int>, greater<int>> ans;

void Recursive(const int index, const int start)
{
	if (m == index)
	{
		queue<pair<int, int>> q;
		int vis[MAX][MAX]{};
		int tmpAns = 0;
		int tmpZero = boardZero;

		for (int i = 0; i < m; ++i)
		{
			int y = tmpV[i].first;
			int x = tmpV[i].second;

			q.push({ y, x });
			vis[y][x] = 1;
		}

		int dy[4]{ -1, 1, 0, 0 };
		int dx[4]{ 0, 0, -1, 1 };
		while (false == q.empty())
		{
			auto cur = q.front();
			q.pop();

			int cy = cur.first;
			int cx = cur.second;

			if (0 == tmpZero)
			{
				break;
			}

			for (int dir = 0; dir < 4; ++dir)
			{
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (ny < 0 or n <= ny or nx < 0 or n <= nx)
				{
					continue;
				}
				if (1 == board[ny][nx] or vis[ny][nx])
				{
					continue;
				}
				else if (0 == board[ny][nx])
				{
					--tmpZero;
				}

				q.push({ ny, nx });
				vis[ny][nx] = vis[cy][cx] + 1;
				tmpAns = max(tmpAns, vis[ny][nx]);
			}
		}

		if (0 == tmpZero)
		{
			ans.push(tmpAns);
		}

		return;
	}

	const int VLENGTH = v.size();
	for (int i = start; i < VLENGTH; ++i)
	{
		tmpV[index] = v[i];
		Recursive(index + 1, i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			int what;
			cin >> what;
			board[y][x] = what;
			if (2 == what)
			{
				v.push_back({ y, x });
			}
			else if (0 == what)
			{
				++boardZero;
			}
		}
	}

	Recursive(0, 0);
	if (ans.empty())
	{
		cout << -1;
	}
	else
	{
		int reAns = ans.top() - 1;
		cout << (reAns < 0 ? 0 : reAns);		
	}

	return 0;
}