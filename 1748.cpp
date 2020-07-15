#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int board[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	int check = 10;
	int sum = 1;
	for (int i=1; i<=n; ++i)
	{
		if (check <= i)
		{
			check *= 10;
			++sum;
		}
		ans += sum;
	}

	cout << ans;

	return 0;
}