#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// n : 사다리 수
	// m : 뱀 수
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> what;
	for (int idx=0; idx<n+m; ++idx)
	{
		int from, to;
		cin >> from >> to;
		what.push_back({from, to});
	}

	queue<int> q;
	q.push(1); // 1번 부터 탐색

	int ans = 0;
	while (false == q.empty())
	{
		int size = q.size();
		vector<bool> v(100+1);
		while (size--)
		{
			int cur = q.front();
			q.pop();

			if (100 == cur) // 목적지 달성하였으면 탈출
			{
				goto JUMP;
			}

			for (int idx=1; idx<=6; ++idx) // 주사위는 1~6까지 있으므로 모두 다 시도
			{
				int pos = cur + idx;
				for (auto curWhat : what)
				{
					if (pos == curWhat.first)
					{
						pos = curWhat.second;
						break;
					}
				}

				if (v[pos]) // 중복된 수 제거
				{
					continue;
				}
				
				if (0 <= pos and pos <= 100) //해당 범위 내에 있으면 탐색할 자격 충분
				{
					v[pos] = true;
					q.push(pos);
				}
			}
		}

		++ans; //시도 횟수
	}

JUMP:
	cout << ans;
	
	return 0;
}