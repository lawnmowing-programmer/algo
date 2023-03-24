#include <iostream>

using namespace std;

int n, m, a, b, cards[100004], prefix_sum[100004];
int temp;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
		temp +=cards[i];
		prefix_sum[i + 1] = temp;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << prefix_sum[b] - prefix_sum[a - 1] << '\n';
	}
	return 0;
}
