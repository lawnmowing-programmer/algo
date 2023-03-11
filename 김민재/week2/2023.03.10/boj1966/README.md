# [BoJ 1966 수 찾기](https://www.acmicpc.net/problem/1966)

solved.ac Silver III

## 카테고리

구현, 자료 구조, 시뮬레이션, 큐

## 시간복잡도

시간복잡도는 O(N^2)이다.

## 풀이

입력받은 리스트를 그 index와 함께 양방향 큐로 변환해주고, 리스트는 높은 우선순위 순으로 정렬해준다.

```python
priority_list = list(map(int, sys.stdin.readline().split()))
queue = deque(enumerate(priority_list))
priority_list.sort(reverse=True)
```

높은 우선순위 순으로 정렬된 순서와 일치하는 문서가 나올 때 까지 큐에서 1개씩 빼서 큐에 다시 넣는다. 뺀 문서가 목표로 한 문서라면, 지금까지 뺀 횟수를 결과 리스트에 추가하고 반복문을 탈출한다.

```python
count = 0
for priority in priority_list:
    while (doc := queue.popleft())[1] != priority:
        queue.append(doc)
    count += 1
    if doc[0] == M:
        answer.append(count)
        break
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/c5e9c4a1570d483a96fd5a654a7bcea1)