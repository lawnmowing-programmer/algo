#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[102][102];
bool vis[102][102];
int n,m,k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[102];
int idx = 0;

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	while(k--)
	{
		int x,y,x2,y2;
		cin >> x >> y >> x2 >> y2;
		for (int i = y; i < y2; i++)
		{
			for (int j = x; j < x2; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && vis[i][j] == 0)
			{
				cnt++;
				int sum = 1;
				vis[i][j] = 1;
				queue<pair<int, int>> Q;
				Q.push({i,j});
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (board[nx][ny] == 1 || vis[nx][ny] == 1)
							continue;
						vis[nx][ny] = 1;
						sum++;
						Q.push({nx,ny});
					}
				}
				arr[idx] = sum;
				idx++;			
			}
		}
	}
	sort(arr, arr + idx);
	cout << cnt << '\n';
	for (int i = 0; i < idx; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}
