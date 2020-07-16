#include <bits/stdc++.h>
using namespace std;

int save[100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string msg;
	cin >> msg;

	int ans = 0;

	stack<int> s;
	const int LENGTH = msg.length();
	for (int i=0; i<LENGTH; ++i)
	{
		char what = msg[i];
		if ('(' == what or '[' == what)
		{
			s.push(what);
		}
		else
		{
			if (true == s.empty())
			{
				cout << 0;
				return 0;
			}

			char compare = s.top();
			if ('(' == compare and ')' != what
				or '[' == compare and ']' != what)
			{
				cout << 0;
				return 0;
			}
			
			int value = what == ')' ? 2 : 3;
			int depth = s.size();

			if (0 != save[depth + 1])
			{
				value *= save[depth + 1];
				save[depth + 1] = 0;
			}

			save[depth] += value;

			if (1 == depth)
			{
				ans += save[depth];
				save[depth] = 0;
			}
			s.pop();
		}
	}

	if (false == s.empty())
	{
		cout << 0;
		return 0;
	}

	cout << ans;

	return 0;
}