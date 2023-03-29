#include <bits/stdc++.h>

using namespace std;

int N,K;

int senser[10002];
int dst[10002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i=0; i<N; i++)
		cin >> senser[i];
	sort(senser, senser + N);
	for (int i=1; i<N; i++)
		dst[i] = senser[i] - senser[i-1];
	sort(dst + 1, dst + N);
	int ans = 0;
	for (int i=1; i<=N-K; i++)
		ans += dst[i];
	cout << ans;
}
