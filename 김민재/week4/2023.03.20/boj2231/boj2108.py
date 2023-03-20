import sys

N = int(sys.stdin.readline())

decomposition_origin = 0
for num in range(max(1, N-len(str(N))*9), N):
    if num + sum(map(int, str(num))) == N:
        decomposition_origin = num
        break

sys.stdout.write(str(decomposition_origin))
