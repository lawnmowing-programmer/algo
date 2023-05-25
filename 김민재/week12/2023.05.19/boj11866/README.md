# [BoJ 11866 요세푸스 문제 0](https://www.acmicpc.net/problem/11866)

solved.ac Silver V

## 카테고리

구현, 자료 구조, 큐

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

입력을 받아 1~N 배열을 만들어준다.

```python
import sys

N, K = map(int, sys.stdin.readline().split())

que = list(range(1, N + 1))
```

순서를 계산해서 해당 순서를 pop해준다.

```python
index = 0
result = []

while que:
    index += K - 1
    index %= len(que)
    result.append(str(que.pop(index)))

sys.stdout.write('<' + ", ".join(result) + ">\n")
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/b8213a6e13bd4e5d907ce4e02226bf81)
