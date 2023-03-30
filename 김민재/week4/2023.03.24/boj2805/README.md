# [BoJ 2805 나무 자르기](https://www.acmicpc.net/problem/2805)

solved.ac Silver II

## 카테고리

이분 탐색, 매개 변수 탐색

## 시간복잡도

시간복잡도는 가장 긴 나무의 높이를 H라고 할 때, O(N * logH)이다.

## 풀이

입력값을 Counter를 사용해 빈도수 dict으로 바꿔준다.

```python
trees = Counter(map(int, sys.stdin.readline().split()))
```

가능한 가장 작은 높이인 0을 start로, 가장 높은 높이인 가장 긴 나무의 높이를 end로 설정한다.
이를 기반으로 이분탐색을 실행한다.
start와 end가 교차되는 순간 end의 값이 목표 값이다.

```python
start, end = 0, max(trees)
while start <= end:
    mid = (start + end) // 2
    log = sum((tree_hight - mid) * i for tree_hight, i in trees.items() if tree_hight > mid)

    if log >= M:
        start = mid + 1
    else:
        end = mid - 1
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/894dcebd9cd6441ab5843866a4fab9c4)
