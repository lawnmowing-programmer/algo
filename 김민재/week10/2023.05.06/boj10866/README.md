# [BoJ 10866 덱](https://www.acmicpc.net/problem/10866)

solved.ac Silver IV

## 카테고리

자료 구조, 덱

## 시간복잡도

시간복잡도는 O(n)이다.

## 풀이

입력받은 커맨드대로 deque를 이용해 큐 역할을 수행하는 반복문을 만들어 주었다.

```python
import sys
from collections import deque

inputs = sys.stdin.read().splitlines()[1:]

deq = deque()
result = []
for command in inputs:
    if command.startswith("push_front"):
        deq.appendleft(command.split()[1])
    if command.startswith("push_back"):
        deq.append(command.split()[1])
    elif command == "pop_front":
        result.append(deq.popleft() if deq else "-1")
    elif command == "pop_back":
        result.append(deq.pop() if deq else "-1")
    elif command == "size":
        result.append(str(len(deq)))
    elif command == "empty":
        result.append("0" if deq else "1")
    elif command == "front":
        result.append(deq[0] if deq else "-1")
    elif command == "back":
        result.append(deq[-1] if deq else "-1")

sys.stdout.write('\n'.join(result))
```

## 결과

결과 : [맞았습니다!!](http://boj.kr/cc2fcd5a145040f595a4d81aaeaa09ea)
