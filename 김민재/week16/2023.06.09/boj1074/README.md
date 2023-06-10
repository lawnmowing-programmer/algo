# [BoJ 1074 Z](https://www.acmicpc.net/problem/1074)

solved.ac Silver I

## 카테고리

분할 정복, 재귀

## 시간복잡도

시간복잡도는 O(logN)이다.

## 풀이

영역을 4분면으로 나눠 4분면의 어느 분면에 속하는지 체크해 순서를 알아낸다.

```python
import sys

N, r, c = map(int, sys.stdin.readline().split())

result = 0
for n in range(N, 0, -1):
    split_point = 2 ** (n - 1)
    if r >= split_point and c >= split_point:
        result += 3 * (split_point ** 2)
        r %= split_point
        c %= split_point
    elif r >= split_point:
        result += 2 * (split_point ** 2)
        r %= split_point
    elif c >= split_point:
        result += split_point ** 2
        c %= split_point

sys.stdout.write(str(result))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/d7c4d86fa9c145b690150c01cc13e294)
