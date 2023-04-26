#include <iostream>

using namespace std;

int park[104];
int A, B, C;
int a, b;
int ret;

int main()
{
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		for (int j = a; j < b; j++)
		{
			park[j]++;
		}
	}
	for (int i = 1; i < 101; i++)
	{
		if (park[i] == 0)
			continue;
		else if (park[i] == 1)
			ret += A;
		else if (park[i] == 2)
			ret += B*2;
		else if (park[i] == 3)
			ret += C*3;
	}
	cout << ret;
	return 0;
}
