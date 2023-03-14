#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[22][22];

struct block
{
	int area;
	// 해당 그룹의 일반 블록 번호
	int num;
	// 기준 블록의 좌표
	pair<int, int> standard;
	// 일반 블록의 좌표를 담는 배열
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> coor;
	// rainbow 블록의 좌표를 담는 배열
	vector<pair<int, int>> rainbow;
	block(int num) : num(num), area(0){};
};

block find_group()
{
	block max_group(-1);
	bool vis[22][22] = {0};
	queue<pair<int, int>> q;
	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j >= 0; j--)
			if (board[i][j] > 0 && !vis[i][j])
			{
				vis[i][j] = true;
				q.push({i, j});
				block target(board[i][j]);
				target.coor.push({i, j});
				target.num = board[i][j];
				while (!q.empty())
				{
					auto [x, y] = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = x + "1012"[dir] - '1';
						int ny = y + "0121"[dir] - '1';
						if (nx < 0 || ny < 0 || nx >= N || ny >= N)
							continue;
						if (vis[nx][ny] || board[nx][ny] == -1)
							continue;
						if (board[nx][ny] == 0)
							target.rainbow.push_back({nx, ny});
						else
						{
							if (target.num != board[nx][ny])
								continue;
							target.coor.push({nx, ny});
						}
						vis[nx][ny] = true;
						q.push({nx, ny});
					}
				}
				target.area = target.coor.size() + target.rainbow.size();
				target.standard = target.coor.top();
				if (target.area >= 2)
				{
					if (target.area > max_group.area)
						max_group = target;
					else if (target.area == max_group.area)
					{
						if (target.rainbow.size() > max_group.rainbow.size())
							max_group = target;
						else if (target.rainbow.size() == max_group.rainbow.size())
						{
							if (target.standard.first > max_group.standard.first)
								max_group = target;
							else if (target.standard.first == max_group.standard.first)
								if (target.standard.second > max_group.standard.second)
									max_group = target;
						}
					}
				}
				// 무지개 블록은 탐색을 다시 진행해야 하기 때문에 vis를 false로 바꿔줌.
				for (auto e : target.rainbow)
				{
					auto [x, y] = e;
					vis[x][y] = false;
				}
			}
	return (max_group);
}

void gravity()
{
	for (int j = 0; j < N; j++)
	{
		int idx = N - 1;
		for (int i = N - 1; i >= 0; i--)
		{
			if (board[i][j] == -2)
				continue;
			if (board[i][j] == -1)
				idx = i - 1;
			else
				swap(board[idx--][j], board[i][j]);
		}
	}
}

void rotate()
{
	int tmp[22][22];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = board[N - 1 - j][i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = tmp[i][j];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	int ans = 0;
	while (1)
	{
		block max_group = find_group();
		// 그룹이 존재하지 않으면 탐색 종료
		if (max_group.num == -1)
			break;
		ans += max_group.area * max_group.area;
		while (!max_group.coor.empty())
		{
			auto [x, y] = max_group.coor.top();
			max_group.coor.pop();
			board[x][y] = -2;
		}
		for (auto e : max_group.rainbow)
		{
			auto [x, y] = e;
			board[x][y] = -2;
		}
		gravity();
		rotate();
		rotate();
		rotate();
		gravity();
	}
	cout << ans;
}
