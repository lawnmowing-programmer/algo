#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int visited[150004];
int before_pos[150004];
int n, k, temp;
queue<int> q;
vector<int> v;

int main()
{
    cin >> n >> k;
    visited[n] = 1;
    q.push(n);
    while (q.size())
    {
        temp = q.front();
        q.pop();
        if (temp == k)
            break;
        for (int i : {temp + 1, temp - 1, temp * 2})
        {
            if (i < 0 || i > 150000 || visited[i] != 0)
                continue;
            visited[i] = visited[temp] + 1;
            before_pos[i] = temp;
            q.push(i);
        }
    }

    cout << visited[temp] - 1 << '\n';
    while (temp != n)
    {
        v.push_back(temp);
        temp = before_pos[temp];
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for (auto i : v)
        cout << i << ' ';
    return 0;
}