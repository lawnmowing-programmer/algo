#include <bits/stdc++.h>

using namespace std;

int N;
int A[502][502];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int dust_x[4][10] = 
{
	{-2,-1,-1,-1,0,1,1,1,2,0},
	{2,1,1,0,0,0,0,-1,-1,1},
	{-2,-1,-1,-1,0,1,1,1,2,0},
	{-2,-1,-1,0,0,0,0,1,1,-1},
};
int dust_y[4][10] = 
{
	{0,-1,0,1,-2,-1,0,1,0,-1},
	{0,-1,1,-2,-1,1,2,-1,1,0},
	{0,1,0,-1,2,1,0,-1,0,1},
	{0,-1,1,-2,-1,1,2,-1,1,0},
};
double dust_rat[4][9] = 
{
	{0.02, 0.1, 0.07, 0.01, 0.05, 0.1, 0.07, 0.01, 0.02},
	{0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01},
	{0.02, 0.1, 0.07, 0.01, 0.05, 0.1, 0.07, 0.01, 0.02},
	{0.05, 0.1, 0.1, 0.02, 0.07, 0.07, 0.02, 0.01, 0.01},
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	queue<tuple<int,int,int,int>> q;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			cin >> A[i][j];
	q.push({N/2,N/2,0,2});
	int ans = 0;
	while (!q.empty())
	{
		auto [x,y,dir,len] = q.front(); q.pop();
		int tmp = len / 2;
		while (tmp--)
		{
			x += dx[dir];
			y += dy[dir];
			int a = 0;
			for (int dust_dir=0; dust_dir < 10; dust_dir++)
			{
				int nx = x + dust_x[dir][dust_dir];
				int ny = y + dust_y[dir][dust_dir];
				int dust;
				// a가 있는 지점에서는 나머지 dust를 더해줌.
				if (dust_dir == 9)
					dust = A[x][y] - a;
				else 
					dust = A[x][y] * dust_rat[dir][dust_dir];
				// 격자 밖으로 넘어간 모래의 양 더해줌.
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					ans += dust;
				else
					A[nx][ny] += dust;
				a += dust;
			}
			A[x][y] = 0;
		}
		// N이 홀수이므로 무조건 y가 음수가 되는 지점에서 탐색이 마무리됨.
		if (y < 0)
			break;
		q.push({x,y,(dir + 1) % 4, len + 1});
	}
	cout << ans;
}
