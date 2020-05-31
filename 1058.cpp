#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> friends; // 친구들 보관소
	for (int idx=0; idx<n; ++idx)
	{
		string msg;
		cin >> msg;
		friends.push_back(msg);
	}

	int ans = 0;
	for (int yidx = 0; yidx < n; ++yidx) // 친구 인원수 만큼 일단 다 한번 순회는 해야함
	{
		vector<bool> vis(n);
		string& curFriend = friends[yidx]; //해당 행 친구목록들
		for (int xidx=0; xidx<n; ++xidx) // 해당 행에 해당하는 열 친구들 한번씩 다 순회
		{
			if ('Y' == curFriend[xidx]) //친구라면
			{
				vis[xidx] = true; //그 열에 대한 친구 표시
				string& refFriend = friends[xidx]; //해당 친구의 친구까지 친구인지 탐색해야 함
				for (int jidx=0; jidx<n; ++jidx) //그 친구들도 한번씩 다 돌면서 친구 체크에 넣어주면 된다.
				{
					if ('Y' == refFriend[jidx] and false == vis[jidx])
					{
						vis[jidx] = true;
					}
				}
			}
		}
		vis[yidx] = false; // 나 자신은 친구에서 제외

		// 친구 목록 체크한거를 돌면서 카운트 세어주고
		int cnt = 0;
		for (auto cur : vis)
		{
			if (true == cur)
			{
				++cnt;
			}
		}
		ans = max(ans, cnt); //가장 큰 값을 찾아주면 된다.
	}

	cout << ans; // 결과 출력

	return 0;
}