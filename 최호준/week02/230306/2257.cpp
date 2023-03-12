#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0)->sync_with_stdio(0)

array<int, 101> st;
array<int, 26> dict ;
string str;

void invoke(int i, int last, int depth)
{
    if (str[i] == '\0')
        return;
    if (isalpha(str[i]))
        st[depth] += last = dict[str[i] - 'A'];
    if (isdigit(str[i]))
    {
        int val = str[i] - '0';
        val = last * (val - 1); // st[depth]에는 이미 val값이 한 번 더해진 상태이다. 따라서 하나를 빼서 더해준다.
        st[depth] += val;
    }
    if (str[i] == '(')
        st[++depth] = 0;
    if (str[i] == ')')
    {
      last = st[depth--];
    	st[depth] += last;
    }
invoke(i + 1, last, depth);
}

void solution()
{
    dict['H' - 'A'] = 1;
    dict['C' - 'A'] = 12;
    dict['O' - 'A'] = 16;
    invoke(0, 0, 0);
    cout << st[0] << '\n';
}

void input()
{
    cin >> str;
}

int main()
{
    FASTIO;

    input();
    solution();
}
