#include <bits/stdc++.h>
using namespace std;

// a = 출발 장대, b = 도착 장대, n = 탑 갯수
// 탑이 n개일 때
// n - 1을 비어있는 장대로 빼놓고 n을 b장대로 옮긴 후 다시 n - 1을 b로 옮긴다.
void hanoi(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	hanoi(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	hanoi(6 - a - b, b, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	//k만큼 옮길 때 a만큼 이동을 해야 한다면,
	//n이 k라면 k - 1만큼 비어 있는 장대로 옮기는데 a번
	// n을 b장대로 옮기는데 1번
	// k - 1만큼 6 - a - b에서 b로 옮기는데 a번
	// = 2k + 1;
	//시프트연산자 (1<<n) ==> 2^n
	cout << (1<<n) - 1 << '\n';
	hanoi(1, 3, n);
	return 0;
}