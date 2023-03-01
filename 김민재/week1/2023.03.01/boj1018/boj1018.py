import sys

M, N = map(int, sys.stdin.readline().split())

board = [sys.stdin.readline().rstrip() for m in range(M)]
color_check = [[0 for n in range(N)] for m in range(M)]

for m in range(M):
    for n in range(N):
        color_check[m][n] += ('W' if (m + n) % 2 == 0 else 'B') != board[m][n]

result = []

for m in range(M - 7):
    for n in range(N - 7):
        x = sum(sum(color_check[i][n:n + 8]) for i in range(m, m + 8))
        result.append(min(x, 64 - x))

sys.stdout.write(str(min(result)))
