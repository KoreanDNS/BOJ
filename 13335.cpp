#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int board[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, w, l;
	cin >> n >> w >> l; // w : 다리의 길이 l : 다리의 최대 하중
	
	for (int idx=0; idx<n; ++idx)
	{
		cin >> board[idx];
	}

	int ans = 0;
	queue<pair<int, int>> q;
	for (int i=0; i<n;)
	{
		int what = board[i];
		if (what <= l)
		{
			l -= what;
			q.push({ what, w });
			++i;
		}
		
		const int QSIZE = q.size();
		for (int j=0; j<QSIZE; ++j)
		{
			auto cur = q.front();
			q.pop();
			if (0 == --cur.second)
			{
				l += cur.first;
				continue;
			}
			q.push(cur);
		}
		++ans;
	}

	int QSIZE;
	while (QSIZE = q.size())
	{
		for (int j = 0; j<QSIZE; ++j)
		{
			auto cur = q.front();
			q.pop();
			if (0 == --cur.second)
			{
				
				l += cur.first;
				continue;
			}
			q.push(cur);
		}
		++ans;
	}

	cout << ans+1;

	return 0;
}