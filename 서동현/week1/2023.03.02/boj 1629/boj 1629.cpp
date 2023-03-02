#include <bits/stdc++.h>
using namespace std;

// 필요한 수학적 개념
// 1.
//    7 * 7 * 7 * 7 % 5
// = (7 * 7 * 7 * 7) % 5
// = (7 % 5) * (7 % 5) * (7 % 5) * (7 % 5) % 5
// 2.
// 시간복잡도를 생각해서 재귀를 통해 b를 2로 나눠서 계산
// (2^6 = (2^3) * (2^3))
// int 오버플로우를 고려해서 long long 선언, c로 나눈 나머지만 가지고 연산
long long pow(long long a, long long b, long long c)
{
	if (b == 1)
		return a % c;
	long long val = pow(a, b / 2, c);
	val = val * val % c;
	// 홀 수일 땐 a를 한 번 더 곱해준다.
	if (b % 2 == 0)
		return val;
	return val * a % c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c;
	cin >> a >> b >> c;
	cout << pow(a, b, c);
	return 0;
}