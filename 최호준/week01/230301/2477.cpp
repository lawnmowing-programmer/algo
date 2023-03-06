#include <iostream>
#include <bits/stdc++.h>

#define E 1
#define W 2
#define S 3
#define N 4

using namespace std;

/*
 * 1. 6각형의 좌표를 구한다.
 * 2. 좌표를 기반으로 넓이를 구한다.
 * 3. 단위를 곱한다.
*/

typedef struct s_point
{
    int x;
    int y;
} t_point;

array<t_point, 7> points;
int unit;

int polygonArea()
{
    int area = 0;
    int j = 5;

    for (int i = 0; i < 6; i++)
    {
        area += (points[j].x + points[i].x) *
                (points[j].y - points[i].y);
        j = i;
    }
    return area / 2;
}

void solution()
{
    cout << polygonArea() * unit << '\n';
}

void set_point(int dir, int len, int last_idx)
{
    points[last_idx + 1] = points[last_idx];

    if (dir == E)
        points[last_idx + 1].x = points[last_idx].x + len;
    else if (dir == W)
        points[last_idx + 1].x = points[last_idx].x - len;
    else if (dir == S)
        points[last_idx + 1].y = points[last_idx].y + len;
    else if (dir == N)
        points[last_idx + 1].y = points[last_idx].y - len;
}

void input()
{
    int dir;
    int len;

    cin >> unit;
    for (int i = 0; i < 6; i++)
    {
        cin >> dir >> len;
        set_point(dir, len, i);
    }
    points[0] = points[6];
}

int main()
{
    input();
    solution();
}
