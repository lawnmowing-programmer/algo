# [BoJ 2231 분해합](https://www.acmicpc.net/problem/2231)

solved.ac Bronze II

## 카테고리

브루트포스 알고리즘

## 시간복잡도

시간복잡도는 O(N * log N)이다.

## 풀이

기본적으로 입력받은 N보다 작은 수를 탐색하며 분해합을 계산해 N과 동일한 숫자를 찾는 그리디 로직을 구현했다. 여기서 시간복잡도를 줄이는 핵심은 1부터 전체 범위를 탐색하는 것이 아니라, N의 자리수에 따른 가능한 최소값을 구하는 것이다.

```python
decomposition_origin = 0
for num in range(max(1, N-len(str(N))*9), N):
    if num + sum(map(int, str(num))) == N:
        decomposition_origin = num
        break
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/3ca62fa552ef40ccbc76d5f5ac51ef56)