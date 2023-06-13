# [BoJ 1107 리모컨](https://www.acmicpc.net/problem/1107)

solved.ac Gold V

## 카테고리

브루트포스 알고리즘

## 시간복잡도

시간복잡도는 상수다.

## 풀이

가능한 범위를 브루트포스 알고리즘을 사용해 최소값을 찾는다.

```python
import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
if M:
    broken = sys.stdin.readline().split()
else:
    broken = []

result = abs(100 - N)
for num in range(1000001):
    for button in str(num):
        if button in broken:
            break
    else:
        result = min(result, len(str(num)) + abs(num - N))

sys.stdout.write(str(result))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/266fef12ca774fa1a632fdde5efb59cb)
