# [BoJ 15829 Hashing](https://www.acmicpc.net/problem/15829)

solved.ac Bronze II

## 카테고리

구현, 문자열, 해싱

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

문자열의 각 문자에 대해 공식을 적용해 그 총 합을 구해 Hashing 결과를 도출한다.

```python
import sys

L = int(sys.stdin.readline())
string = sys.stdin.readline().rstrip()

hash_result = sum((ord(char) - ord('a') + 1) * (31 ** i) for i, char in enumerate(string)) % 1234567891

sys.stdout.write(str(hash_result))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/84f1fc9598af455da2c2c665c57a7031)
