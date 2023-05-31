#include <iostream>
#include <cstring>

using namespace std;

string str;
unsigned int len;

int main()
{
	getline(cin, str);
	len = str.length();
	for (int i = 0; i < len/2 ; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}
