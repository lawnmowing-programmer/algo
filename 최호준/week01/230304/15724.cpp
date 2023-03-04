#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0)->sync_with_stdio(0)
#define INF 1025

array<array<int, INF>, INF> matrix;
int n, m;
int x, y, xx, yy;

/*
 * 매번 query가 들어올 때마다 합계를 계산하는 방법보단
 * 미리 합을 구하면 O(1) 시간에 답을 구할 수 있다.
 *
 * 시간 복잡도: O(k*(m*n))
 */

void prefix_sum()
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			matrix[j][i] += matrix[j - 1][i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			matrix[i][j] += matrix[i][j - 1];
}

void solution()
{
	cout << matrix[yy][xx] -
		matrix[yy][x - 1] -
		matrix[y - 1][xx] +
		matrix[y - 1][x - 1]
		<< '\n';
}

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> matrix[i][j];
}

int main()
{
	FASTIO;
	int n;
	input();
	prefix_sum();

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> y >> x;
		cin >> yy >> xx;
		solution();
	}
}
