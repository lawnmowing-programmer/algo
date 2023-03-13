#include <bits/stdc++.h>
using namespace std;
int result[3]; //arr[0] = -1 개수, arr[1] = 0 개수, arr[2] = 1 개수
int board[2200][2200];
void rec(int x_start, int x_end, int y_start, int y_end, int num)
{
	if (x_start + 1 == x_end)	//한칸짜리 종이일 때
	{
		if (board[x_start][y_start] == num)
			result[num + 1]++;
		return;
	}
	int check = 1;
	for (int i = x_start; i < x_end; i++)
	{
		for (int j = y_start; j < y_end; j++)
		{
			if (board[i][j] != num)
				check = 0;
		}
	}
	if (check == 1)
	{
		result[num + 1]++;
		return;
	}
	int x_one_third = x_start + (x_end - x_start) / 3;
	int x_two_thirds = x_start + (x_end - x_start) / 3 * 2;
	int y_one_third = y_start + (y_end - y_start) / 3;
	int y_two_thirds = y_start + (y_end - y_start) / 3 * 2;

	
	/*
	1|2|3
	-----
	4|5|6
	-----
	7|8|9
	*/
	rec(x_start, x_one_third, y_start, y_one_third, num);			// 1번 구역
	rec(x_start, x_one_third, y_one_third, y_two_thirds, num);		// 2번 구역
	rec(x_start, x_one_third, y_two_thirds, y_end, num);			// 3번 구역
	
	rec(x_one_third, x_two_thirds, y_start, y_one_third, num);		// 4번 구역
	rec(x_one_third, x_two_thirds, y_one_third, y_two_thirds, num);	// 5번 구역
	rec(x_one_third, x_two_thirds, y_two_thirds, y_end, num);		// 6번 구역
	
	rec(x_two_thirds, x_end, y_start, y_one_third, num);			// 7번 구역
	rec(x_two_thirds, x_end, y_one_third, y_two_thirds, num);		// 8번 구역
	rec(x_two_thirds, x_end, y_two_thirds, y_end, num);				// 9번 구역
	
}

int main ()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	rec(0, n, 0, n, -1);
	rec(0, n, 0, n, 0);
	rec(0, n, 0, n, 1);
	for (int i : result)
		cout << i << '\n';
	return 0;
}