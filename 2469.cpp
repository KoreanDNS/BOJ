#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
char board[MAX][30];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int h;
	cin >> n >> h;

	string target;
	cin >> target;

	for (int i = 0; i < h; ++i)
	{
		cin >> board[i];
	}

	char res[30]{};

	const int TARGET_LENGTH = target.length();
	for (int i = 0; i < n; ++i)
	{
		// 위에서 내려가기
		int uptodownY = 0;
		int uptodownX = i;
		while ('?' != board[uptodownY][0])
		{
			if (0 <= uptodownX - 1 and '-' == board[uptodownY][uptodownX - 1])
			{
				--uptodownX;
			}
			else if ('-' == board[uptodownY][uptodownX])
			{
				++uptodownX;
			}

			uptodownY++;
		}

		int downtoupY = h - 1;
		int downtoupX;

		for (int j = 0; j < TARGET_LENGTH; ++j)
		{
			if (target[j] == 'A' + i)
			{
				downtoupX = j;
				break;
			}
		}

		// 아래에서 올라오기
		while ('?' != board[downtoupY][0])
		{
			if (-1 < downtoupX - 1 and '-' == board[downtoupY][downtoupX - 1])
			{
				--downtoupX;
			}
			else if ('-' == board[downtoupY][downtoupX])
			{
				++downtoupX;
			}

			downtoupY--;
		}

		int dist = abs(uptodownX - downtoupX);
		if (1 < dist)
		{
			string msg;
			for (int i = 0; i < n - 1; ++i)
			{
				msg += 'x';
			}
			cout << msg;
			return 0;
		}

		if (0 == dist)
		{
			if ('\0' == res[uptodownX])
			{
				res[uptodownX] = '*';
			}
		}
		else
		{
			int maxX = max(uptodownX, downtoupX);
			if ('\0' == res[maxX - 1])
			{
				res[maxX - 1] = '-';
			}
		}
	}

	for (int i = 0; i < n - 1; ++i)
	{
		if ('\0' == res[i])
		{
			res[i] = '*';
		}
	}

	bool bFind = false;
	for (int i = 0; i < n - 2; ++i)
	{
		if ('-' == res[i] and '-' == res[i + 1])
		{
			bFind = true;
			break;
		}
	}

	if (bFind)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			cout << 'x';
		}
	}
	else
	{
		res[n - 1] = '\0';
		cout << res;
	}

	return 0;
}