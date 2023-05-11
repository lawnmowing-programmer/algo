# [BoJ 11050 이항 계수 1](https://www.acmicpc.net/problem/11050)

solved.ac Bronze I

## 카테고리

수학, 구현, 조합론

## 시간복잡도

시간복잡도는 O(1)이다.

## 풀이

python의 math 모듈에 있는 comb를 사용해 조합 연산을 수행했다.

```python
import sys
from math import comb

N, K = map(int, sys.stdin.readline().split())

sys.stdout.write(str(comb(N, K)))
```

조합 연산을 직접 수행하면 아래와 같은 공식으로 풀어낼 수 있다. python이 아닌 다른 언어라면 factorial연산이 오버플로우를 일으킬 수 있어 위험하겠지만, python의 arbitrary precision 덕분에 오버플로우 없이 계산할 수 있다.

```python
import sys
from math import factorial

N, K = map(int, sys.stdin.readline().split())

sys.stdout.write(str(factorial(N) // (factorial(K) * factorial(N - K))))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/925930798dde4a3ebfd84fb63d285ed7)
