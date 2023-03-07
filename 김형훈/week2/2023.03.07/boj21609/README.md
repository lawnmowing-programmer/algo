## [BOJ 21609 상어 중학교](https://www.acmicpc.net/problem/21609)

### 카테고리

구현

### 시간복잡도

O\(N의 4승\)

### 풀이

해당 문제에서 중요하게 볼 부분은 다음과 같다.

1. 블록 그룹의 기준 블록은 무지개 블록이 아닌 블록 중에서 행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이다.
2. 격자에 중력이 작용한다.
3. 격자가 90도 반시계 방향으로 회전한다.

1번 부분을 지문에서 처음 접했을때 실수하기 쉽다.  
보통 해당 내용을 구현할 때 탐색 방향을 행의 번호가 작은 순, 열의 번호가 작은 순 이런식으로 구현하는 경우가 있다.  
하지만 너비 우선 탐색을 진행한다고 가정할 때, 탐색의 순서는 거리가 멀어지는 순으로 진행되기 때문에 예외가 발생할 수 있다.  
유효한 좌표들을 priority_queue에 좌표가 작은 순으로 저장해준 뒤, 제일 아래에 있는 좌표를 반환받는 식으로 구현할 수 있다.

2번 부분은 다음과 같이 구현하였다.

```cpp
void gravity()
{
	for (int j=0; j<N; j++)
	{
		int idx = N-1;
		for (int i=N-1; i>=0; i--)
		{
			if (board[i][j] == -2)
				continue ;
			if (board[i][j] == -1)
				idx = i - 1;
			else
				swap(board[idx--][j],board[i][j]);
		}
	}
}
```

반시계 방향으로의 회전은 시계방향 회전을 3번 하면 구현 가능하다.
구현은 다음과 같다.

```cpp
void rotate()
{
	int tmp[22][22];
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			tmp[i][j] = board[N-1-j][i];
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			board[i][j] = tmp[i][j];
}
```

### 결과

[맞았습니다!!](https://www.acmicpc.net/source/share/06556f07e5724bc382bfd232076b29dd)
