## [BOJ 16639 괄호 추가하기 3](https://www.acmicpc.net/problem/16639)

### 카테고리

구현, 완전 탐색

### 시간복잡도

O\(N!\)

### 풀이

요새 cpp09 평가를 다니다 보니 후위표기식 문제를 풀어보고 싶다는 생각이 들었다.  
물론 해당 문제는 다이나믹 프로그래밍을 이용해서 더 최적화된 풀이가 가능하지만 어차피 시간이 넉넉해서 완전 탐색을 이용해 구현을 해보았다.
후위표기식 변환 및 계산 방법은 [해당 글](https://modoocode.com/218)을 참조하였다.

```cpp
// 연산자들에 대해 우선순위를 돌려가며 완전탐색 진행
vector<int> brute(N/2);
for (int i=0; i<N/2; i++)
    brute[i] = i;
do
{

    // ...

} while (next_permutation(brute.begin(), brute.end()));

```

완전탐색을 돌리는 로직이다.  
문제에서 수식이 정해진 포멧대로 주어진다고 해서 편하게 구현하였다.  
\(num, op, num, op, num, ..., num\)
brute\[i\]의 값은 i번째 연산자의 우선순위이다.

```cpp
do
{
    int cnt = 0;
    stack<char> cmp;
    vector<char> post;
    // 우선순위를 바탕으로 후위표기식을 만들어줌.
    for (int i=0; i<N; i++)
    {
        // 홀수번째가 무조건 연산자.
        if (i & 1)
        {
            while (!cmp.empty() && brute[cmp.top()] >= brute[i / 2])
            {
                post.push_back(s[cmp.top() * 2 + 1]);
                cmp.pop();
            }
            cmp.push(i / 2);
        }
        // 짝수번째가 무조건 숫자
        else
            post.push_back(s[i]);
    }
    while (!cmp.empty())
    {
        post.push_back(s[cmp.top() * 2 + 1]);
        cmp.pop();
    }
    // 후위표기식 계산후 ans에 값 갱신
    ans = max(ans, calc_post(post));
} while (next_permutation(brute.begin(), brute.end()))
```

후위표기식을 만들어 준 후 해당 식의 값을 계산해서 ans의 값을 계속 갱신해준다.  
i & 1은 홀수번째 값을 구하는 기믹인데, i % 2로 작성했을 때보다 살짝 더 빠르다.

### 코드

```cpp
#include <bits/stdc++.h>

using namespace std;

int N, ans=INT_MIN;

int calc_post(const vector<char>& tmp)
{
	stack<int> cmp;
	for (char e:tmp)
	{
		if (e >= '0' && e <= '9')
			cmp.push(e - '0');
		else
		{
			// 좋은 변수명이 떠오르지 않았다.
			int yo = 0;
			if (e == '+')
			{
				yo = cmp.top();
				cmp.pop();
				yo += cmp.top();
				cmp.pop();
			}
			else if (e == '-')
			{
				yo -= cmp.top();
				cmp.pop();
				yo += cmp.top();
				cmp.pop();
			}
			else
			{
				yo = cmp.top();
				cmp.pop();
				yo *= cmp.top();
				cmp.pop();
			}
			cmp.push(yo);
		}
	}
	return (cmp.top());
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> N;
	cin >> s;
	// 연산자들에 대해 우선순위를 돌려가며 완전탐색 진행
	vector<int> brute(N/2);
	for (int i=0; i<N/2; i++)
		brute[i] = i;
	do
	{
		int cnt = 0;
		stack<char> cmp;
		vector<char> post;
		// 우선순위를 바탕으로 후위표기식을 만들어줌.
		for (int i=0; i<N; i++)
		{
			// 홀수번째가 무조건 연산자.
			if (i & 1)
			{
				while (!cmp.empty() && brute[cmp.top()] >= brute[i / 2])
				{
					post.push_back(s[cmp.top() * 2 + 1]);
					cmp.pop();
				}
				cmp.push(i / 2);
			}
			// 짝수번째가 무조건 숫자
			else
				post.push_back(s[i]);
		}
		while (!cmp.empty())
		{
			post.push_back(s[cmp.top() * 2 + 1]);
			cmp.pop();
		}
		// 후위표기식 계산후 ans에 값 갱신
		ans = max(ans, calc_post(post));
	} while(next_permutation(brute.begin(), brute.end()));
	cout << ans;
}
```

### 결과

[맞았습니다!!](https://www.acmicpc.net/source/share/13a1db5bef294c53a38a58c044022289)
