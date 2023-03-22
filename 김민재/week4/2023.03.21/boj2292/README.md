# [BoJ 2292 벌집](https://www.acmicpc.net/problem/2292)

solved.ac Bronze II

## 카테고리

수학

## 시간복잡도

시간복잡도는 O(sqrt(N))이다.

## 풀이

육각형을 둘러싸는데에는 계층이 늘어날수록 6의 배수의 육각형이 필요하다. 이를 기반으로 역으로 입력받은 숫자로부터 시작 육각형 1개를 빼고 6만큼씩 늘려가면서 빼주면, 해당 숫자의 육각형이 존재하는 계층에서 입력받은 숫자는 0보다 작거나 같아지게 된다.

```python
N = int(sys.stdin.readline()) - 1

count = 1
while N > 0:
    N -= 6 * count
    count += 1
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/aa2e4ac854534f4080b5148489c8eee1)
