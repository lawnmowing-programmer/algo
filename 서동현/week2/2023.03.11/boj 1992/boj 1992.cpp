#include <bits/stdc++.h>
using namespace std;

string board[66];

void rec(int x_start, int x_end, int y_start, int y_end)
{
	if(x_start + 1 == x_end)
	{
		cout << board[x_start][y_start];
		return;
	}
	int check = 1;
	int sum = 0;	//전부 0일때
	int max_sum = (x_end - x_start) * (y_end - y_start); // 전부 1일 때
	for (int i = x_start; i < x_end; i++)
	{
		for (int j = y_start; j < y_end; j++)
		{
			sum += board[i][j] - '0';
		}
	}
	if (sum == 0 || sum == max_sum)
	{
		cout << board[x_start][y_start];
		return;
	}
	cout << '(';
	int x_half = x_start + (x_end - x_start) / 2;
	int y_half = y_start + (y_end - y_start) / 2;
	rec(x_start, x_half, y_start, y_half);
	rec(x_start, x_half, y_half, y_end);
	rec(x_half, x_end, y_start, y_half);
	rec(x_half, x_end, y_half, y_end);
	cout << ')';
}

int main ()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	rec(0, n, 0, n);
	return 0;
}