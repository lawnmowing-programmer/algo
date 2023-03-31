#include <bits/stdc++.h>

using namespace std;

# define X first
# define Y second

int N;
typedef pair<int,int> pii;
string arr[22];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// c++에서 priority_queue에 custum cmp함수를 전달하기 위해서는
	// functor (class로 감싼 함수)로 전달해야 한다.
	// functor로 함수를 전달하는 방법은 여러가지가 있는데 이중 하나가 아래와 같다.
	auto cmp = [&](const pii& a, const pii& b)
	{
		// 하나의 문자만 비교하는 것이 아닌
		// 뒤의 모든 문자들에 대한 비교가 필요해서 strcmp함수를 이용했다.
		return (strcmp(arr[a.X].c_str() + a.Y, arr[b.X].c_str() + b.Y) > 0);
	};
	cin >> N;
	priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
	for (int i=0; i<N; i++)
	{
		cin >> arr[i];
		// 길이가 더 긴 문자의 우선순위를 높이기 위해 맨 끝에 제일 큰 값을 넣어주었다.
		arr[i].push_back('[');
		pq.push({i, 0});
	}
	while (!pq.empty())
	{
		auto [n,idx] = pq.top();
		pq.pop();
		cout << arr[n][idx];
		if (arr[n][idx + 1] != '[')
			pq.push({n, idx + 1});
	}
}
