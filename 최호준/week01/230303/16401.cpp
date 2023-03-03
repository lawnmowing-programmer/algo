#include <iostream>
#include <bits/stdc++.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define INF 1000000

using namespace std;

/*
	최대 과자의 길이를 이진 탐색으로 찾는다.
	O(Mlog N)
*/

int m, n;
array<int, INF> lens;

int split_snack_by_len(int len)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
            cnt += lens[i] / len;
    return cnt;
}

int bin_search()
{
    int left = 1;
    int right = lens[n - 1];
    int max_len = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (split_snack_by_len(mid) >= m)
        {
            left = mid + 1; 
            max_len = MAX(max_len, mid);
        }
        else 
            right = mid - 1;
    }
    return max_len;
}

void solution()
{
    sort(lens.begin(), lens.begin() + n);
    cout << bin_search() << '\n';
}

void input()
{
    int len;

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        cin >> lens[i];
}

int main()
{
    input();
    solution();
}
