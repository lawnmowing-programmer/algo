import sys

N, M = map(int, sys.stdin.readline().split())
graph = [[float("inf")] * N for _ in range(N)]
for i in range(N):
    graph[i][i] = 0
for _ in range(M):
    i, j = map(lambda x: int(x) - 1, sys.stdin.readline().split())
    graph[i][j] = graph[j][i] = 1

for k in range(N):
    for i in range(N):
        for j in range(N):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

sys.stdout.write(str(min(enumerate(graph), key=lambda x: sum(x[1]))[0] + 1))
