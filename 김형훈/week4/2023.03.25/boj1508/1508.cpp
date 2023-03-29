#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int N,M,K;
int arr[53];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i=0; i<K; i++)
		cin >> arr[i];
	// 이분 탐색을 이용하여 가장 가까운 거리를 구함.
	int st = 0, en = arr[K-1];
	ull ans = 0;
	while (st <= en)
	{
		// 가장 가까운 거리
		int mid = (st + en + 1) / 2;
		int simpan = 1, tmp = 0;
		ull position = 1;
		// 문제에서 사전 순으로 늦는 순으로 출력하라고 했기 때문에
		// 앞에서부터 탐색을 진행해서 조건에 맞는 자리를 찾아준다.
		// (11110, 11101이 조건을 충족할 경우 전자가 답이다.)
		for (int i=1; i<K && simpan < M; i++)
		{
			int dst = arr[i] - arr[tmp];
			// 가장 가까운 거리보다 거리가 먼 구간의 갯수를 구함.
			if (dst >= mid)
			{
				simpan++;
				// K의 범위가 50 이하의 자연수이기 때문에
				// 새로운 container를 만들 필요 없이
				// 비트연산자를 이용해서 값을 저장할 수 있다.
				// 단 literal 1의 경우 int형이기 때문에 31개보다 많은 값을
				// 받으려면 형변환을 해주어야 한다.
				position |= ((ull)1 << i);
				tmp = i;
			}
		}
		if (simpan == M)
		{
			st = mid + 1;
			ans = position;
		}
		// 구간이 M개보다 작을 경우 mid를 너무 넓게 잡아줬기 때문에
		// mid의 길이를 더 짧게 측정해줌.
		else
			en = mid - 1;
	}
	for (int i=0; i<K; i++)
	{
		if (ans & ((ull)1<<i))
			cout << 1;
		else
			cout << 0;
	}
}
