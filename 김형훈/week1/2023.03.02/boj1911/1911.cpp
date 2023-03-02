#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int N, L;
pair<int, int> pos[10002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> pos[i].X >> pos[i].Y;
	sort(pos, pos + N);
	int cur = 0, ans = 0;
	for (int i = 0; i < N; i++)
	{
		// 널빤지가 이미 놓여 있다면 넘어감.
		if (cur >= pos[i].Y)
			continue;
		// 널빤지를 놓기 시작하는 부분을 정함.
		cur = max(cur, pos[i].X);
		int diff = pos[i].Y - cur;
		int cnt = diff / L;
		// 초과하는 부분이 있다면 널빤지를 하나 더 놓음.
		// 이때 널빤지를 놓는 방향은 오른쪽
		if (diff % L != 0)
			cnt++;
		ans += cnt;
		cur += cnt * L;
	}
	cout << ans;
}
