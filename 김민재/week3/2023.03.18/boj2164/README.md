# [BoJ 2164 카드2](https://www.acmicpc.net/problem/2164)

solved.ac Silver IV

## 카테고리

자료 구조, 큐

## 시간복잡도

시간복잡도는 O(log N)이다.

## 풀이

원래 문제의 의도는 큐 자료구조형을 이용해 다음과 같이 문제의 조건을 그대로 실행하는 것이다.

```python
queue = deque(range(1, N+1))

while len(queue) > 1:
    queue.popleft()
    queue.append(queue.popleft())
```

그러나 이 문제는 결과값에 규칙이 있어서 결과값을 수학적 점화식으로 나타낼 수 있다.

```
입력: 2   출력: 2
입력: 3   출력: 2
입력: 4   출력: 4
입력: 5   출력: 2
입력: 6   출력: 4
입력: 7   출력: 6
입력: 8   출력: 8
입력: 9   출력: 2
입력: 10  출력: 4
입력: 11  출력: 6
입력: 12  출력: 8
입력: 13  출력: 10
입력: 14  출력: 12
입력: 15  출력: 14
입력: 16  출력: 16
```

``f(x) = ((입력값) - (2의 n제곱(입력값보다 작은것의 최댓값))) * 2``

따라서 이러한 수식을 코드로 옮기면 다음과 같이 O(log N) 시간복잡도로 해결이 가능하다.

```python
while square < N:
    square *= 2

sys.stdout.write(str(2 * N - square))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/d67a98e2dc854992b0319a27721b895b)