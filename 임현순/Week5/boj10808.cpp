#include <iostream>

using namespace std;

int alpha[26];
string str;

int main()
{
	getline(cin, str);
	for (auto i : str)
	{
		alpha[i - 'a']++;
	}
	for (auto i : alpha)
		cout << i << ' ';
	cout << '\n';
	return 0;
}
