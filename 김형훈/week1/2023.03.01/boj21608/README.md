## [BOJ 21608 상어 초등학교](https://www.acmicpc.net/problem/21608)

### 카테고리

구현, 완전탐색

### 시간복잡도

O\(n의 4승\)

### 풀이

문제의 조건을 그대로 구현해주었다.  
다만 학생의 자리를 정하는 기준이 학생의 정보가 들어오는 순서에 영향을 받기때문에 해당 부분을 고려해주었다.

```cpp
struct info
{
	public:
		pair<int,int> pos;
		int satis;
		bool wanted[402];
		vector<pair<int,int>> near;
};

info students[402];
```

학생의 정보를 보관할 구조체를 만들어주었다.  
어떤 객체를 전역으로 선언할 경우 해당 객체의 멤버변수는 모두 0으로 초기화된다.

```cpp
	for (int i=0; i<N; i++)
	{
		cnt_2[0][i]++;
		cnt_2[N-1][i]++;
		cnt_2[i][0]++;
		cnt_2[i][N-1]++;
	}
```

cnt_2는 인접한 칸의 비어있지 않은 칸을 나타낸다.  
모서리 부분에 해당하는 자리들은 바깥부분이 비어있지 않으므로 1씩 증가해주었다.

```cpp
for (int i=0; i<N*N; i++)
	{
		int cur, prefer;
		cin >> cur;
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

		// 현재 학생이 앉을 수 있는 자리 탐색

		auto [x,y] = students[cur].pos;
		for (int dir=0; dir<4; dir++)
		{
			int nx = x + "1012"[dir] - '1';
			int ny = y + "0121"[dir] - '1';
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue ;
			cnt_2[nx][ny]++;
			students[cur].near.push_back({nx,ny});
			// 선호하는 학생이 근처에 새로 자리를 배정받으면 만족도 증가.
			if (students[board[nx][ny]].wanted[cur])
				students[board[nx][ny]].satis++;
		}
		// 현재 학생의 만족도는 이전 학생 기준으로 결정됨.
		students[cur].satis = cnt_1[x][y];
		board[x][y] = cur;
    }
```

학생의 번호와 그 학생이 선호하는 학생의 번호를 입력받는 부분이다.  
cnt_1에는 인접한 칸 중 이전 탐색에서 **자리를 배정받은 선호 학생**의 수를 나타낸다.  
학생의 near는 자리를 배정받는 순간에 추가되므로 현재 자리를 배정받지 않은 학생은 고려되지 않는다.
만족도를 계산할 때는 이전에 배정받은 학생과 이후 배정받을 학생 모두를 고려해준다.

### 결과

[맞았습니다!!](https://www.acmicpc.net/source/56664732)
