#include <iostream>
#include <queue>

using namespace std;

/*
	시간 제한이 0.1초라서 하나의 pq로만 해결할 수 없다.
	문제에서 중간값을 요구했으므로 mid pq를 만들어보자.
	mid priority queue를 만들기 위해서 
	왼쪽은 max pq 오른쪽은 min_pq를 만든다
*/

priority_queue<int, vector<int>, greater<int>> right_pq;
priority_queue<int> left_pq;

/*
	왼쪽의 몯든 원소는  오른쪽의 모든 원소보다 항상 작다..
*/
void rule_2()
{
	if (left_pq.size() == 0 || right_pq.size() == 0)
		return;
	if (left_pq.top() <= right_pq.top())
		return;

	int l = left_pq.top();
	int r = right_pq.top();
	left_pq.pop();
	right_pq.pop();

	left_pq.push(r);
	right_pq.push(l);
}

/*
	왼쪽의 사이즈는 오른쪽의 사이즈보다 같거나 1만큼 더 크다.
*/
void  rule_1(int val)
{
	if (left_pq.size() > right_pq.size())
		right_pq.push(val);
	else
		left_pq.push(val);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int temp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		rule_1(temp);
		rule_2();
		cout << left_pq.top() << '\n';
	}
}
