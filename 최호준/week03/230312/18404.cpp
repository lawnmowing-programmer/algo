#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct point point;
struct point
{
    int x, y;
};

int n, m;
point st;
array<array<int, 501>, 501> cnts;

int m_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int m_y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool is_valid(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= n &&
           cnts[y][x] == 0;
}

void bfs()
{
    queue<point> q;
    q.push(st);

    while (q.empty() == false)
    {
        point now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int n_x = now.x + m_x[i];
            int n_y = now.y + m_y[i];

            if (is_valid(n_x, n_y) == false)
                continue;
            cnts[n_y][n_x] = cnts[now.y][now.x] + 1;
            q.push({n_x, n_y});
        }
    }
}

void solution(point target)
{
    cout << cnts[target.y][target.x] << ' ';
}

void input()
{
    cin >> n >> m;
    cin >> st.y >> st.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    point target;

    input();
    bfs();
    for (int i = 0; i < m; i++)
    {
        cin >> target.y >> target.x;
        solution(target);
    }
}
