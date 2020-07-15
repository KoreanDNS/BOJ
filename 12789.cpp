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

	vector<int> ans;
	stack<int> s;
	for (int i=0; i<n; ++i)
	{
		int d;
		cin >> d;

		while (false == s.empty() and s.top() < d)
		{
			ans.push_back(s.top());
			s.pop();
		}
		s.push(d);
	}

	while (false == s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}

	
	vector<int> compare(ans);
	sort(ans.begin(), ans.end());

	for (int i = 0; i < n; ++i)
	{
		if (ans[i] != compare[i])
		{
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";
	
	return 0;
}