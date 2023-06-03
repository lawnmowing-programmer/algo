# [BoJ 18111 마인크래프트](https://www.acmicpc.net/problem/18111)

solved.ac Silver II

## 카테고리

구현, 브루트포스 알고리즘

## 시간복잡도

시간복잡도는 O(N * M * H)이다.

## 풀이

데이터 입력

```python
import sys

N, M, B = map(int, sys.stdin.readline().split())
landscape = [block for _ in range(N) for block in map(int, sys.stdin.readline().split())]
```

사용할 수 있는 총 블럭 개수 계산

```python
able_blocks = sum(landscape) + B
```

최소 평탄화 소요 시간 계산

```python
min_time = float('inf')
result_height = 0
for height in range(min(landscape), max(landscape) + 1):
    if able_blocks >= height * N * M:
        time = 0
        for block_height in landscape:
            diff = block_height - height
            if diff > 0:
                time += diff * 2
            else:
                time -= diff * 1

        if time <= min_time:
            min_time = time
            result_height = height
    else:
        break
```

결과 출력

```python
sys.stdout.write(str(min_time) + ' ' + str(result_height))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/2bea503526f64c4a928720c3fdefc416)
