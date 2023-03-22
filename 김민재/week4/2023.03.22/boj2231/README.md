# [BoJ 2775 부녀회장이 될테야](https://www.acmicpc.net/problem/2775)

solved.ac Bronze I

## 카테고리

수학, 구현, 다이나믹 프로그래밍

## 시간복잡도

시간복잡도는 O(Tkn)이지만 문제에서 k와 n의 범위가 1~14로 정의되어 있기 때문에 이러한 매우 작은 값의 범위는 사실상 무시할 수 있다.
따라서 O(T)로 표현을 해도 무방하다.

## 풀이

입력을 슬라이싱해서 k와 n을 한 묶음으로 반복문을 실행한다.

```python
for k, n in zip(inputs[::2], inputs[1::2]):
```

DP의 메모이제이션을 적용하기 위해 한 층만큼의 배열을 생성한다.

```python
floor = [population for population in range(1, n + 1)]
```

k층의 n호까지 반복하며 누적 연산을 실행한다.

```python
for i in range(k):
    for j in range(1, n):
        floor[j] += floor[j - 1]
```

연산 완료 후 가장 마지막 요소가 알아내야 할 호수의 값이다.

```python
result.append(floor[-1])
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/35e9d70ff645425eb8f5f67e88b5dade)
