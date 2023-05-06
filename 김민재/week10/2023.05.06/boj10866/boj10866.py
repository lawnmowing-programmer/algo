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
