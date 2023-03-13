import sys
from collections import deque

T = int(sys.stdin.readline())
answer = []

for _ in range(T):
    N, M = map(int, sys.stdin.readline().split())
    priority_list = list(map(int, sys.stdin.readline().split()))
    queue = deque(enumerate(priority_list))
    priority_list.sort(reverse=True)
    count = 0
    for priority in priority_list:
        while (doc := queue.popleft())[1] != priority:
            queue.append(doc)
        count += 1
        if doc[0] == M:
            answer.append(count)
            break

sys.stdout.write('\n'.join(map(str, answer)))
