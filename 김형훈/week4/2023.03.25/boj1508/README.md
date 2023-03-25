## [BOJ 1508 레이스](https://www.acmicpc.net/problem/1508)

### 카테고리

이분 탐색

### 시간복잡도

O\(logK\)

\( 1 <= K <= 50 \)

### 풀이

[공유기](https://www.acmicpc.net/problem/2110) 문제와 굉장히 비슷한 문제.

가장 가까운 두 심판의 거리를 a라고 할 때, a를 기준으로 심판을 최대한 많이 배치한다고 가정해보자.
a의 길이를 짧게 측정하면 배치할 수 있는 심판의 수가 많아질 것이다.  
반대로 a의 길이를 너무 길게 측정하면 배치할 수 있는 심판의 수가 적어질 것이다.  
이를 토대로 M명의 심판을 배치할 때, a의 최댓값을 구하는 코드를 구현할 수 있다.

```cpp
    int st = 0, en = arr[K-1];
	ull ans = 0;
	while (st <= en)
	{
		// 가장 가까운 거리
		int mid = (st + en + 1) / 2;
		int simpan = 1, tmp = 0;
		// 문제에서 사전 순으로 늦는 순으로 출력하라고 했기 때문에
		// 앞에서부터 탐색을 진행해서 조건에 맞는 자리를 찾아준다.
		// (11110, 11101이 조건을 충족할 경우 전자가 답이다.)
        ull position = 1;
		// position은 배치한 자리를 저장할 변수.
        // 거리를 최대한 멀게 해야 하고, 사전 순으로 가장 늦는 경우의 수를 선택해야 하므로
        // 첫번째 자리는 무조건 배치하여야 해서 1부터 시작했다.
		for (int i=1; i<K && simpan < M; i++)
		{
			int dst = arr[i] - arr[tmp];
			if (dst >= mid)
			{
				simpan++;
				position |= ((ull)1 << i);
				tmp = i;
			}
		}
		if (simpan >= M)
		{
			st = mid + 1;
			ans = position;
		}
		else
            en = mid - 1;
    }
```

이분탐색을 이용해서 구현해보았다.

K의 범위가 50보다 작은 자연수로, unsigned long long 메모리에 저장할 수 있는 범위이기 때문에 vector나 array같은 새로운 container를 따로 선언하지 않고, 비트연산자를 이용해서 구현하였다.  
[비트연산자에 대한 흥미로운 기믹](https://blog.naver.com/jinhan814/222623538092)

### 코드

```cpp
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
```

### 결과

[맞았습니다!!](https://www.acmicpc.net/source/share/103be3e86774485cae43760d95d9dc29)
