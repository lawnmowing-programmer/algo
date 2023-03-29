# [BoJ 2798 블랙잭](https://www.acmicpc.net/problem/2798)

solved.ac Bronze II

## 카테고리

브루트포스 알고리즘

## 시간복잡도

시간복잡도는O(N^3)이다.

## 풀이

itertools의 combinations을 사용해 3개의 카드로 구성될 수 있는 조합을 찾아서 그 중 M보다 작은 최대값을 찾는다.

```python
result = 0
for selected_cards in combinations(cards, 3):
    temp = sum(selected_cards)
    if result < temp <= M:
        result = temp
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/2a85af5614424b19a2ed607ed78bf606)
