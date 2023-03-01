## [BOJ 21608 상어 초등학교](https://www.acmicpc.net/problem/21608)

### 카테고리

구현, 완전탐색

### 시간복잡도

O\(N의 4제곱\)

### 풀이

N의 범위가 20으로 크지 않기 때문에 완전탐색으로 구현 가능하다.  
문제에서 제시한 우선순위에 따라 입력받은 순으로 학생의 자리를 정해주면 된다.  
매번 학생의 자리를 정할 때 필요한 정보는

1. 비어있는 칸 중 현재 탐색을 진행하는 학생이 선호하는 학생이 인접한 수
2. 비어있는 칸 중 인접한 칸이 비어있는 수
3. 학생별 만족도

1은 탐색을 진행하는 학생마다 다른 값을 가지므로 매 탐색마다 새로 배열을 선언해준다.

```cpp

// 학생의 정보를 구조체의 배열에 담아주었다.
struct info
{
	public:
		// 학생의 위치
		pair<int,int> pos;
		// 만족도
		int satis;
		// 학생이 선호하는 학생 정보
		bool wanted[402];
		// 학생 주변 칸의 좌표.
		// 탐색을 마친 후에 할당된다.
		vector<pair<int,int>> near;
};

info students[402];

// 칸 별 비어있지 않은 인접한 칸의 수 정보.
int cnt_2[22][22];
// 칸에 배정된 학생의 정보
int board[22][22];
// ...

// 모서리 쪽 자리의 인접하지 않은 칸의 수를 늘려줌.
for (int i=0; i<N; i++)
{
	cnt_2[0][i]++;
	cnt_2[N-1][i]++;
	cnt_2[i][0]++;
	cnt_2[i][N-1]++;
}

// 학생별 탐색 진행
for (int i=0; i<N*N; i++)
{
	int cur, prefer;
	cin >> cur;
	// 1의 조건을 참조할 배열 선언
	int cnt_1[22][22] = {0};
	for (int j=0; j<4; j++)
	{
		cin >> prefer;
		students[cur].wanted[prefer] = true;
		for (auto e:students[prefer].near)
		{
			auto [x,y] = e;
			cnt_1[x][y]++;
		}
	}

	// ...
}
```

2번 조건의 경우 모서리쪽 자리는 인접한 칸이 비어있지 않은걸로 간주하기 때문에 해당 부분을 예외처리 해주었다.
이후 조건에 맞는 위치를 탐색해주었다.

```cpp

// ...

int tmp_1 = 0, tmp_2 = 5;
// 왼쪽 위 부분부터 탐색을 해서 3번 조건을 맞춰준다.
for (int i=0; i<N; i++)
	for (int j=0; j<N; j++)
	{
		if (board[i][j])
			continue ;
		if (cnt_1[i][j] > tmp_1)
		{
			students[cur].pos = {i,j};
			tmp_1 = cnt_1[i][j];
			tmp_2 = cnt_2[i][j];
		}
		else if (cnt_1[i][j] == tmp_1)
		{
			if (cnt_2[i][j] < tmp_2)
			{
				students[cur].pos = {i,j};
				tmp_2 = cnt_2[i][j];
			}
		}
	}

// ...

```

학생을 배정해 준 후 학생의 만족도를 계산해준다.  
이때 학생의 만족도는 이전에 배정받은 학생과 이후의 배정받을 학생을 고려해야한다.

```cpp
		auto [x,y] = students[cur].pos;
		// 배정이 완료된 학생에 한하여 인접한 칸의 정보를 저장함.
		for (int dir=0; dir<4; dir++)
		{
			int nx = x + "1012"[dir] - '1';
			int ny = y + "0121"[dir] - '1';
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue ;
			cnt_2[nx][ny]++;
			// 이후 인접한 칸에 선호하는 학생이 배정된 학생의 만족도를 올려줌.
			students[cur].near.push_back({nx,ny});
			if (students[board[nx][ny]].wanted[cur])
				students[board[nx][ny]].satis++;
		}
		// 이전에 배정된 학생들의 정보로 만족도를 저장해줌.
		students[cur].satis = cnt_1[x][y];
		board[x][y] = cur;
```

### 결과

[맞았습니다!!](https://www.acmicpc.net/source/56664732)
