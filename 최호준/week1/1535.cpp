#include <iostream>
#include <bits/stdc++.h>

#define MAX(a, b) (((a) > (b) ? (a) : (b)))

using namespace std;

/*
    TLE 
    brute force : 20! = 20 * 19 * ... * 1 = 2432902008176640000  
*/

/*
 * 해결 방법: 
 *   	dp[인사 대상][현재 체력] = 현재까지의 최대 행복 
 *  	i : 인사 대상
 *  	j : 현재 체력
 *
 *  	if i 번 사람과 인사가 가능 :
 *  		dp[i][j] = MAX(현재 사람과 인사 수행 X, 현재 사람과 인사 수행 O)
 *  		dp[i][j]  = MAX(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i])  
 *  				[참고] 
 *  					j - L[i]로 찾는 이유: j - L[i]는 전 단계에서 i와 인사하기 전 상태를 의미한다.
 *  	else i 번 사람과 인사를 할 수 없다면 :
 *			dp[i][j] = dp[i-1][j] 
 *	
 * 주의사항:
 * 		체력을 감소시킨 후, 행복을 계산한다.
 * 		만약 감소시킨 후 체력이 0이면 행복을 느낄 수 없다,
 * 		예시:
 * 			L = 100 , J = 100
 * 			현재 체력이 100 인 경우
 * 				100 - L == 0 이므로 어떠한 행복도 느낄 수 없다.
 * 
 * 예시:
 *		n: 3
 *		L: 1 21 79
 *		J: 20 30 25
 * 		대상\체력	  1	  2    3  .... 21   22  23  ...    79 ... 99
 *			1       0   20   20      20   20  20  ...    20 ... 20
 *			2       0   20   20 .... 20   30  50  ...    50 ... 50
 *			3       0   20   20 .... 20   30  50  ...    50 ... 50   
 */

array<int, 21> L;
array<int ,21> J;
array<array<int, 101>, 21> dp;
int n;

void solution()
{

    for (int i = 1; i <= n; i++) // i :사람
	{  for (int j = 1; j <= 100; j++) // j : 현재 체력 
        {
			dp[i][j] = dp[i-1][j]; 
			if (L[i] < j) // i와 인사 가능
				dp[i][j] = MAX(dp[i][j], dp[i - 1][j - L[i]] + J[i]);
		}
	}
	cout << dp[n][100] << '\n';
}

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> L[i];
	for (int i = 1; i <= n; i++)
		cin >> J[i];
}

int main()
{
    input();
    solution();
}
