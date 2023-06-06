# [BoJ 10845 큐](https://www.acmicpc.net/problem/10845)

solved.ac Silver IV

## 카테고리

자료 구조, 큐

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

입력받은 커맨드대로 deque를 이용해 큐 역할을 수행하는 반복문을 만들어 주었다.

```python
deq = deque()
result = []
for command in inputs:
    if command.startswith("push"):
        deq.append(command.split()[1])
    elif command == "pop":
        result.append(deq.popleft() if deq else "-1")
    elif command == "size":
        result.append(str(len(deq)))
    elif command == "empty":
        result.append("0" if deq else "1")
    elif command == "front":
        result.append(deq[0] if deq else "-1")
    elif command == "back":
        result.append(deq[-1] if deq else "-1")
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/c7eee719eaf14d72b8d323c7a41e4c58)
