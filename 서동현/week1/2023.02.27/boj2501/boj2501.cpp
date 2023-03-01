#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[10002];
int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int j = 1;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			arr[j] = i;
			j++;
		}
	}
	cout << arr[k];
	return 0;
}