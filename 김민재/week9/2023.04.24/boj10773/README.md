# [BoJ 10773 제로](https://www.acmicpc.net/problem/10773)

solved.ac Silver IV

## 카테고리

구현, 자료 구조, 스택

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

입력받은 숫자들을 확인해 숫자가 0이면 stack의 가장 마지막 요소를 pop하고, 0이 아니면 stack에 추가해준다.

```python
stack = []
for money in inputs:
    if money:
        stack.append(money)
    else:
        stack.pop()
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/bf7d684a0d304ae986ab264727a556db)
