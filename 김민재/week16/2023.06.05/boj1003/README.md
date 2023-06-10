# [BoJ 1003 피보나치 함수](https://www.acmicpc.net/problem/1003)

solved.ac Silver III

## 카테고리

다이나믹 프로그래밍

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

0과 1이 나오는 순서를 최소부터 누적해 올라가면서 횟수 계산을 해준다.

```python
for testcase in testcases:
    zero_count, one_count = 1, 0
    for _ in range(testcase):
        zero_count, one_count = one_count, zero_count + one_count
    result.append('{} {}'.format(zero_count, one_count))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/682d08b9ecc34940a1017206c681b552)
