#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 *                  (div,mod)
	1인당 보석 수 |  R  |  B   | 보석을 가진 사람의 수
		7 			1,0   0,4  =  2
		6           1,1   0,4  =  3
		5           1,2   0,4  =  3
		4           1,3   1,0  =  3
		3           2,1   1,1  =  5
		2           3,1   2,0  =  6 => 불가능
		1           7,0   4,0  =  11 => 불가능

	최악의 경우의 완전탐색 시간 복잡도
		n = 10 ^ 9
		m = 300,000 = 3 * 10 ^ 5
		n * m => 10^14
		문제 제한 시간이 1초라서 통과할 수 없다.

	탐색 알고리즘 중 구현이 쉬운 이진탐색
		n = log (10 ^ 9) => 30
		m = 300,000 = 3 * 10 ^ 5
		n * m => 10 ^ 6
*/

#define MAX 300000
#define INF 1000000000
array<int, MAX> jewels;
int n_child;
int n_jewels;

int bin_search()
{
	int left = 1;
	int right = INF;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int _n_child = 0;
		for (int i = 0; i < n_jewels; i++)
		{
			if (jewels[i] % mid == 0)
				_n_child += jewels[i] / mid;
			else
				_n_child += jewels[i] / mid + 1;
		}
		if (_n_child > n_child)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return left;
}

void solution()
{
	cout << bin_search() << '\n';
}

void input()
{
	cin >> n_child >> n_jewels;
	for (int i = 0; i < n_jewels; i++)
		cin >> jewels[i];
}

int main()
{
	input();
	solution();
}
