#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[70][70];
bool vis[70][70];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void my_swap(int x, int y, int len)
{
	int tmp[70][70] = {0};
	int n = (1<<(len + 1));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			tmp[x + j][y + n - 1 - i] = A[x + i][y + j];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			A[x + i][y + j] = tmp[x + i][y + j];
}

void fire(int L, int x, int y, int i)
{
	if (L < 0)
		return ;
	// 재귀적으로 구간을 나눈 이후 시계방향으로 돌려준다.
	if (L == i)
	{
		my_swap(x, y, i);
		return ;
	}
	fire(L, x, y, i - 1);
	fire(L, x + (1<<i), y, i - 1);
	fire(L, x, y + (1<<i), i - 1);
	fire(L, x + (1<<i), y + (1<<i), i - 1);
}

// bfs 특성상 indent가 깊습니다.
// 더 줄일수가 없네요 ㅜㅜ
pair<int,int> bfs()
{
	int ans_1 = 0;
	int ans_2 = 0;
	for (int i=1; i<=(1<<N); i++)
		for (int j=1; j<=(1<<N); j++)
		{
			ans_1 += A[i][j];
			if (vis[i][j] || A[i][j] == 0)
				continue ;
			queue<pair<int,int>> q;
			vis[i][j] = true;
			q.push({i,j});
			int cnt = 1;
			while (!q.empty())
			{
				auto [x,y] = q.front();
				q.pop();
				for (int dir=0; dir<4; dir++)
				{
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 1 || ny < 1 || nx > (1<<N) || ny > (1<<N))
						continue ;
					if (vis[nx][ny] || A[nx][ny] == 0)
						continue ;
					cnt++;
					vis[nx][ny] = true;
					q.push({nx,ny});
				}
			}
			ans_2 = max(ans_2, cnt);
		}
	// pair 구조체를 만들어주는 std 내장 함수
	return (make_pair(ans_1, ans_2));
}

void melt()
{
	// 얼음이 동시에 놓아야 하기 때문에
	// 놓아야 하는 칸을 target에 담아둔 후 한번에 놓여줌.
	queue<pair<int,int>> target;
	for (int i=1; i<=(1<<N); i++)
		for (int j=1; j<=(1<<N); j++)
		{
			if (A[i][j] == 0)
				continue ;
			int cnt = 0;
			for (int dir=0; dir<4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				cnt += (A[nx][ny] != 0);
			}
			if (cnt < 3)
				target.push({i,j});
		}
	while (!target.empty())
	{
		auto [x,y] = target.front(); target.pop();
		A[x][y]--;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> Q;
	for (int i=1; i<=(1<<N); i++)
		for (int j=1; j<=(1<<N); j++)
			cin >> A[i][j];
	while (Q--)
	{
		int L; cin >> L;
		fire(L - 1, 1, 1, N - 1);
		melt();
	}
	pair<int,int> ans = bfs();
	cout << ans.first << '\n' << ans.second;
}
