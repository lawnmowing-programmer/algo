#include <bits/stdc++.h>

using namespace std;

int N;
int cnt_2[22][22];
int board[22][22];

struct info
{
	public:
		pair<int,int> pos;
		int satis;
		bool wanted[402];
		vector<pair<int,int>> near;	
};

info students[402];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0; i<N; i++)
	{
		cnt_2[0][i]++;
		cnt_2[N-1][i]++;
		cnt_2[i][0]++;
		cnt_2[i][N-1]++;
	}
	for (int i=0; i<N*N; i++)
	{
		int cur, prefer;
		cin >> cur;
		int cnt_1[22][22] = {0};
		for (int j=0; j<4; j++)
		{
			cin >> prefer;
			students[cur].wanted[prefer] = true;
			for (auto e:students[prefer].near)
			{
				auto [x,y] = e;
				cnt_1[x][y]++;
			}
		}
		int tmp_1 = 0, tmp_2 = 5;
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
			{
				if (board[i][j])
					continue ;
				if (cnt_1[i][j] > tmp_1)
				{
					students[cur].pos = {i,j};
					tmp_1 = cnt_1[i][j];
					tmp_2 = cnt_2[i][j];
				}
				else if (cnt_1[i][j] == tmp_1)
				{
					if (cnt_2[i][j] < tmp_2)
					{
						students[cur].pos = {i,j};
						tmp_2 = cnt_2[i][j];
					}
				}
			}
		auto [x,y] = students[cur].pos;
		for (int dir=0; dir<4; dir++)
		{
			int nx = x + "1012"[dir] - '1';
			int ny = y + "0121"[dir] - '1';
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue ;
			cnt_2[nx][ny]++;
			students[cur].near.push_back({nx,ny});
			if (students[board[nx][ny]].wanted[cur])
				students[board[nx][ny]].satis++;
		}
		students[cur].satis = cnt_1[x][y];
		board[x][y] = cur;
	}
	int ans = 0;
	for (int i=1; i<=N*N; i++)
	{
		switch (students[i].satis)
		{
			case 1:
				ans += 1;
				break;
			case 2:
				ans += 10;
				break;
			case 3:
				ans += 100;
				break;
			case 4:
				ans += 1000;
				break;
		}
	}
	cout << ans;
}
