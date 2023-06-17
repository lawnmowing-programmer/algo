# [BoJ 1389 케빈 베이컨의 6단계 법칙](https://www.acmicpc.net/problem/1389)

solved.ac Silver I

## 카테고리

그래프 이론, 그래프 탐색, 너비 우선 탐색, 플로이드–워셜

## 시간복잡도

시간복잡도는 O(n^3)이다.

## 풀이

그래프의 서로 연결된 노드를 1로, 연결 안된 노드를 INF로 표시하는 2차원 배열을 만든다.

```python
import sys

N, M = map(int, sys.stdin.readline().split())
graph = [[float("inf")] * N for _ in range(N)]
for i in range(N):
    graph[i][i] = 0
for _ in range(M):
    i, j = map(lambda x: int(x) - 1, sys.stdin.readline().split())
    graph[i][j] = graph[j][i] = 1
```

플로이드–워셜 알고리즘을 이용해서 노드간 최소 거리를 계산한다.

```python
for k in range(N):
    for i in range(N):
        for j in range(N):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
```

각 행의 합을 계산해 케빈 베이컨 수를 구한 후, 가장 작은 요소의 번호를 출력한다.

```python
sys.stdout.write(str(min(enumerate(graph), key=lambda x: sum(x[1]))[0] + 1))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/682d08b9ecc34940a1017206c681b552)
