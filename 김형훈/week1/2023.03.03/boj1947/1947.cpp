# include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;
int N;
long long dp[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[2] = 1;
	for (int i=3; i<=N; i++)
		dp[i] = (dp[i-1] + dp[i-2]) * (i-1) % MOD;
	cout << dp[N];
}
