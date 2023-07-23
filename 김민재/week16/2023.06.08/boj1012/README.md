# [BoJ 1012 유기농 배추](https://www.acmicpc.net/problem/1012)

solved.ac Silver II

## 카테고리

그래프 이론 ,그래프 탐색 ,너비 우선 탐색 ,깊이 우선 탐색

## 시간복잡도

시간복잡도는 O(N * M)이다.

## 풀이

데이터를 입력받고 전처리한다.

```python
for testcase in range(int(sys.stdin.readline())):
    M, N, K = map(int, sys.stdin.readline().split())
    cabbage_field = [[False] * M for _ in range(N)]
    for _ in range(K):
        X, Y = map(int, sys.stdin.readline().split())
        cabbage_field[Y][X] = True
```

전처리 된 데이터를 기반으로 순회하며 배추가 존재하면 배추 군락을 구분하는 bfs를 돌고 출력한다.

```python
    cluster_count = 0
    for x in range(M):
        for y in range(N):
            if cabbage_field[y][x]:
                bfs(x, y)
                cluster_count += 1

    sys.stdout.write(str(cluster_count) + '\n')
```

사방의 배추 여부를 확인하고, queue를 이용해 bfs를 수행한다.

```python
def bfs(start_x_pos, start_y_pos):
    que = deque()
    dxs = [-1, 1, 0, 0]
    dys = [0, 0, -1, 1]

    que.append((start_x_pos, start_y_pos))
    cabbage_field[start_y_pos][start_x_pos] = False

    while que:
        x_pos, y_pos = que.popleft()

        for dx, dy in zip(dxs, dys):
            nx = x_pos + dx
            ny = y_pos + dy

            if M > nx >= 0 and N > ny >= 0 and cabbage_field[ny][nx]:
                que.append((nx, ny))
                cabbage_field[ny][nx] = False
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/08686030f388485aa410a4316687b57d)
