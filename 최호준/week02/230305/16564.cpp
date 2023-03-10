#include <iostream>
#include <bits/stdc++.h>

/*
    이분탐색 문제
        시간 복잡도 : O(M*log N)  N 은 MAX_LEVEL, M은 사람 수
*/

using namespace std;

#define FASTIO cin.tie(0)->sync_with_stdio(0)
#define INF 1000000
#define MAX_LEVEL 1000000000

int n;
int k;
array<int, INF> levels;

int is_okay_use(int target)
{
    int now_k = 0;

    for (int i = 0; i < n; i++)
    {
        if (levels[i] < target)
            now_k += target - levels[i];
        if (now_k > k)
            return false;
    }
    return true;
}

int bin_search()
{
    int left = 1;
    int right = MAX_LEVEL + 1; // +1을 안하면 MAX_LEVEL -1 까지만 탐색한다
    int max_level = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (is_okay_use(mid))
        {
            max_level = max(max_level, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return max_level;
}

void solution()
{
    cout << bin_search() << endl;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> levels[i];
}

int main()
{
    FASTIO;

    input();
    solution();
}
