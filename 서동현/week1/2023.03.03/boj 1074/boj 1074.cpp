#include <bits/stdc++.h>
using namespace std;

/*
구역 나누기
1번			2번
  0  1 |  4  5
  2  3 |  6  7
-------|-------
  8  9 | 12 13
 10 11 | 14 15
3번			4번

ex) n = 2, r = 0, c = 2라면, half * half(1번구역 넓이 = 4) + rec_z(n - 1, r, c - half)(작은 사각형 1번 구역 = 0)
	4 출력
*/
int rec_z(int n, int r, int c)
{
	if(n == 0)	//base condition
		return 0;
	int half = 1 << (n - 1);	// 한 변의 절반 == 2^(n-1)
	if (r < half && c < half)			//1번 구역
		return rec_z(n-1, r, c);
	else if (r < half && c >= half)		//2번 구역
		return half * half  + rec_z(n - 1, r, c - half);
	else if (r >= half && c < half)		//3번 구역
		return half * half * 2 + rec_z(n - 1, r - half, c);
	else								//4번 구역
		return half * half * 3 + rec_z(n -1, r - half, c - half); 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,r,c;
	cin >> n >> r >> c;
	cout << rec_z(n, r, c);
	return 0;
}