import sys

N, K = map(int, sys.stdin.readline().split())

que = list(range(1, N + 1))
index = 0
result = []

while que:
    index += K - 1
    index %= len(que)
    result.append(str(que.pop(index)))

sys.stdout.write('<' + ", ".join(result) + ">\n")
