# [BoJ 10828 스택](https://www.acmicpc.net/problem/10828)

solved.ac Silver IV

## 카테고리

자료 구조, 스택

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

입력받은 커맨드대로 스택 역할을 수행하는 반복문을 만들어 주었다.

```python
stack = []
result = []
for command in inputs:
    if command.startswith("push"):
        stack.append(command.split()[1])
    elif command == "pop":
        result.append(stack.pop() if stack else "-1")
    elif command == "size":
        result.append(str(len(stack)))
    elif command == "empty":
        result.append('0' if stack else '1')
    elif command == "top":
        result.append(stack[-1] if stack else "-1")
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/400f92f5c98344928a35e0fbd118a733)
