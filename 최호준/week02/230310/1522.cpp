#include <iostream>
#include <bits/stdc++.h>

/*
    a와 b로만 이루어진 문자열이 주어질 때,
    a를 모두 연속으로 만들기 위해서 필요한 교환의 회수를 최소로 하는 프로그램을 작성하시오.
     
    슬라이딩 윈도우를 위해서 deqeue를 사용하면 쉽게 풀린다.
*/

using namespace std;

#define FASTIO cin.tie(0)->sync_with_stdio(0)

int n;
deque<char> dq;

int counting(char target, int len)
{
    int cnt = 0;

    for (auto iter = dq.begin(); iter != dq.begin() + len; iter++)
        if (*iter == target)
            cnt++;
    return cnt;
}

void solution()
{
    int cnt_of_a = counting('a', n);
    int ans = 5001;

    for (int i = 0; i < n; i++)
    {
        int cnt_of_b = counting('b', cnt_of_a);
        ans = min(ans, cnt_of_b);

        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << ans;
}

void input()
{
    string s;

    cin >> s;
    n = s.length();
    for (auto c : s)
        dq.push_back(c);
}

int main()
{
    FASTIO;

    input();
    solution();
}