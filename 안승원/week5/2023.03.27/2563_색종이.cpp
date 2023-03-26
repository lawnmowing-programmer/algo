#include <iostream>

int main()
{
	int n, paper[100][100] = {{0}}, x, y, cnt = 0;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> x;
		std::cin >> y;
		for (int i = x; i < x + 10; i++)
			for (int j = y; j < y + 10; j++)
				if (paper[i][j] == 0)
					++paper[i][j];
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (paper[i][j] == 1)
				++cnt;
	std::cout << cnt;
	return (0);
}
