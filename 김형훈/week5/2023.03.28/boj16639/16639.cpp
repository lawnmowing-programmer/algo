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
