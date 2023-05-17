# [BoJ 9012 괄호](https://www.acmicpc.net/problem/9012)

solved.ac Silver IV

## 카테고리

자료 구조, 문자열, 스택

## 시간복잡도

전체 문자열의 길이의 합을 n이라고 할 때, 시간복잡도는 O(n)이고, 공간복잡도는 O(n)이다.

## 풀이

기본적으로 여는 괄호의 개수와 닫는 괄호의 개수가 같은지 체크를 한다.
그 과정에서, 여는 괄호가 나오기 전 닫는 괄호가 나올 때 (parenthesis_count < 0), 혹은 남은 문자열의 길이가 닫혀야 할 여는 괄호의 개수보다 적을 때 (len(line) - 1 - i < parenthesis_count) 조기종료를 한다.

```python
for line in inputs:
    parenthesis_count = 0
    for i, char in enumerate(line):
        if char == '(':
            parenthesis_count += 1
        elif char == ')':
            parenthesis_count -= 1
        if len(line) - 1 - i < parenthesis_count or parenthesis_count < 0:
            break
    result.append("YES" if parenthesis_count == 0 else "NO")
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/d5baede744b0414dbb1b1f965cbbfe40)
