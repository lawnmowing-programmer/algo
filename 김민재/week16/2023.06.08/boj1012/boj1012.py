import sys
from collections import deque


def bfs(start_x_pos, start_y_pos):
    que = deque()
    dxs = [-1, 1, 0, 0]
    dys = [0, 0, -1, 1]

    que.append((start_x_pos, start_y_pos))
    cabbage_field[start_y_pos][start_x_pos] = False

    while que:
        x_pos, y_pos = que.popleft()

        for dx, dy in zip(dxs, dys):
            nx = x_pos + dx
            ny = y_pos + dy

            if M > nx >= 0 and N > ny >= 0 and cabbage_field[ny][nx]:
                que.append((nx, ny))
                cabbage_field[ny][nx] = False


for testcase in range(int(sys.stdin.readline())):
    M, N, K = map(int, sys.stdin.readline().split())
    cabbage_field = [[False] * M for _ in range(N)]
    for _ in range(K):
        X, Y = map(int, sys.stdin.readline().split())
        cabbage_field[Y][X] = True

    cluster_count = 0
    for x in range(M):
        for y in range(N):
            if cabbage_field[y][x]:
                bfs(x, y)
                cluster_count += 1

    sys.stdout.write(str(cluster_count) + '\n')
