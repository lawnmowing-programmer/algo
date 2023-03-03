#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;
	int n;
	for (int i = 0; i < 5; i++)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if (a + b + c + d > sum)
		{
			sum = a + b + c + d;
			n = i + 1;
		}
	}
	cout << n << '\n';
	cout << sum;
	return 0;
}