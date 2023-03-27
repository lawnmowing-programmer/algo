## [BOJ 1294 문자열 장식](https://www.acmicpc.net/problem/1294)

### 카테고리

그리디, 정렬

### 시간복잡도

O\(log\(N\*|S|\)\*|S|\)

priority_queue에 삽입하는 문자의 갯수 \* strcmp

### 풀이

간단하게 생각하면 각 문자열마다 제일 첫번째 문자들을 비교한 후 제일 작은 것을 추가하면 문제를 해결할 수 있을것 처럼 보인다.  
물론 해당 문제를 풀이하는 기본적인 로직은 맞지만, 다음과 같은 예외를 잘 처리해야 한다.

```cpp
5
KOOSAGA
XIAOWUC
DOTORYA
CKI
THENITROMEFAN
```

해당 예제에서 매번 각 문자열들의 앞부분을 비교해서 제일 작은 문자만 골랐다고 가정해보자. CDKIKOOOSAGA까지 고른 후의 문자열들의 상황은 다음과 같다.

```cpp
(null)
XIAOWUC
TORYA
(null)
THENITROMEFAN
```

이때 나는 TORYA의 T를 골라야 할까 THEN...의 T를 골라야 할까?  
각각의 값을 골랐을 경우의 답은 다음과 같다.

```cpp
// TORYA를 골랐을 경우
CDKKIOOOSAGATORTHENITROMEFANXIAOWUCYA
// THEN...을 골랐을 경우
CDKIKOOOSAGATHENITORTROMEFANXIAOWUCYA
```

후자가 답인것은 명확하다.  
그렇다면 해당 예시를 통해 알 수 있는 사실은 만약 비교하는 값들 중 같은 값이 있을때의 예외처리가 필요하다는 사실이다.  
비교하는 두 문자 이후의 값들도 비교해서 결국에 더 작은 문자열의 문자를 선택하는 방식으로 구현할 수 있다.

```cpp
#include <bits/stdc++.h>

using namespace std;

# define X first
# define Y second

int N;
deque<char> cmp[22];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	cin >> N;
	for (int i=0; i<N; i++)
	{
		cin >> a;
		// pop_front를 하기 위해 deque에 문자들을 담아줌.
        for (char e:a)
			cmp[i].push_back(e);
	}
	while (1)
	{
        // 매번 sort를 해주면 우선순위가 더 높은 문자열이 앞에 온다.
		sort(cmp, cmp+N);
		pair<char, int> target = {92, -1};
		for (int i=0; i<N; i++)
		{
			if (cmp[i].empty())
				continue ;
			if (cmp[i].front() < target.X)
				target = {cmp[i].front(), i};
		}
		if (target.Y == -1)
			return (0);
		cout << target.X;
		cmp[target.Y].pop_front();
	}
}
```

해당 코드는 priority_queue를 이용하면 다음과 같이 간단하게 나타낼 수 있다.

```cpp
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
		pq.push({i, 0});
	}
	while (!pq.empty())
	{
		auto [n,idx] = pq.top();
		pq.pop();
		cout << arr[n][idx];
		if (idx + 1 < arr[n].size())
			pq.push({n, idx + 1});
	}
}
```

cpp에서 priority_queue에 우선순위 비교를 위한 함수를 전달하기 위해서는 functor로 전달해야 한다.  
[cpp에서 priority_queue에 함수를 전달하는 여러가지 기믹들](https://www.acmicpc.net/blog/view/114)

하지만 해당 방식으로도 여전히 다음과 같은 예외사항이 발생한다.

```cpp
3
DBABBBA
DBABB
DBAB
```

일단 처음에 'D'문자를 고를 때 우리는 어떤 문자열의 'D'를 골라야 할까?  
위에서 구현한 방식대로라면 제일 아래에 있는 문자열의 'D'를 고를 것이다.  
그렇게 한다면 DBAB까지 세번째 문자열의 문자를 고른 후 첫번째, 2번째 문자열의 문자들을 골라 답은 DBABDBABB...가 될 것이다.  
이는 첫번째 문자열의 문자를 고른 경우인 DBABBBA...보다 작은 값이다.  
즉 만약 비교하는 두 문자열이 서로 포함관계에 있을 경우, 길이가 더 긴 문자열의 문자를 골라야 한다는 가설을 세워볼 수 있다.  
해당 가설을 바탕으로 거짓이 되는 예외들을 생각하다보면 모두 sort나 strcmp 함수 선에서 해결이 된다는 사실을 알 수 있다. 경우의 수가 매우 많으므로 자세한 설명은 생략하도록 하겠다.  
문자열 마다 제일 큰 문자를 하나 추가해주면 sort함수나 strcmp 함수에서 길이가 긴 문자를 더 짧은 문자열로 판단하도록 할 수 있다.

### 코드

```cpp
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
```

### 결과

[맞았습니다!!](https://www.acmicpc.net/source/share/5d3aa2fbca8a489aa1160cde199c0070)
