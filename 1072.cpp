#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll x, y;
	cin >> x >> y;

	ll target = 100 * y / x;
	if (99 <= target)
	{
		cout << -1;
		return 0;
	}

	ll st = 0;
	ll en = 1000000000;

	while (st < en)
	{
		ll mid = (st + en) / 2;
		ll midV = 100 * (y + mid) / (x + mid);
		if (target < midV)
		{
			en = mid;
		}
		else
		{
			st = mid + 1;
		}
	}

	cout << st;
	
	return 0;
}