# [BoJ 1018 체스판 다시 칠하기](https://www.acmicpc.net/problem/1018)

solved.ac Silver IV

## 카테고리

브루트포스 알고리즘

## 시간복잡도

코드의 전체 시간복잡도는 O(MN + (M-7)(N-7))이며, M과 N이 7에 비해 충분히 크면 O(MN)으로 단순화 할 수 있다.

## 풀이

입력받은 보드와 같은 크기의 2차원 배열을 만들어서 W와 B가 교차로 나오지 않는 지점들을 1로 저장한다.

```python
board = [sys.stdin.readline().rstrip() for m in range(M)]
color_check = [[0 for n in range(N)] for m in range(M)]

for m in range(M):
    for n in range(N):
        color_check[m][n] += ('W' if (m + n) % 2 == 0 else 'B') != board[m][n]
```

위에서 저장한 2차원 배열에서 모든 경우의 8 * 8 크기의 구역에 대한 색칠이 필요한 칸의 갯수를 배열로 저장한다.

```python
result = []

for m in range(M - 7):
    for n in range(N - 7):
        x = sum(sum(color_check[i][n:n + 8]) for i in range(m, m + 8))
        result.append(min(x, 64 - x))
```

저장된 칸의 갯수들 중 가장 작은 요소를 출력한다.

```python
sys.stdout.write(str(min(result)))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/3097e93bb97e4020a313ba51214b6055)