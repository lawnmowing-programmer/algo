#include <iostream>
#include <bits/stdc++.h>

/*
 * 분할정복
 */

#define INF 128
#define W 0
#define B 1
using namespace std;

array<array<int, INF>, INF> board;
int n;
int w_ans;
int b_ans;

bool conquer_ret_is_end(int x, int y, int size)
{
	int w_cnt = 0;
	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++)
			if (board[i][j] == W)
				w_cnt++;

	if (w_cnt == size * size)
	{
		w_ans++;
		return true;
	}
	else if (w_cnt == 0)
	{
		b_ans++;
		return true;
	}
	return false;
}

void divide_conquer(int x, int y, int size)
{
	if (size == 0)
		return;

	if (conquer_ret_is_end(x, y, size))
		return;
	size /= 2;
	divide_conquer(x, y, size);
	divide_conquer(x + size, y, size);
	divide_conquer(x, y + size, size);
	divide_conquer(x + size, y + size, size);
}

void solution()
{
	divide_conquer(0, 0, n);
	cout << w_ans << '\n'
		<< b_ans << '\n';
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
}

int main()
{
	input();
	solution();
}
