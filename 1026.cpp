#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v1(n);
	vector<int> v2(n);

	for (int idx=0; idx<n; ++idx)
	{
		cin >> v1[idx];
	}

	for (int idx = 0; idx < n; ++idx)
	{
		cin >> v2[idx];
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<int>());

	int ans = 0;
	for (int idx=0; idx<n; ++idx)
	{
		ans += v1[idx] * v2[idx];
	}

	cout << ans;

	return 0;
}