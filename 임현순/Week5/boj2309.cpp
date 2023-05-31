#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heights;
int inp;

int main()
{
	for (int i = 0; i < 9 ; i++)
	{
		cin >> inp;
		heights.push_back(inp);
	}
	sort(heights.begin(), heights.end());
	do
	{
		inp = 0;
		for (int i = 0; i < 7; i++)
			inp += heights[i];
		if (inp == 100)
		{
			for (int i = 0; i < 7; i++)
				cout << heights[i] << ' ';
			break;
		}
	}while(next_permutation(heights.begin(), heights.end()));
	return 0;
}
