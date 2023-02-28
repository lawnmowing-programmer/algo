#include <bits/stdc++.h>
using namespace std;

int n,yes=0,no=0;
int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		if (num == 1)
			yes++;
		else
			no++;
	}
	if (yes < no)
		cout << "Junhee is not cute!";
	else
		cout << "Junhee is cute!";
	return 0;
}