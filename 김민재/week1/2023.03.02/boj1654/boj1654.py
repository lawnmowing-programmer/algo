import sys

K, N = map(int, sys.stdin.readline().split())
cables = [int(sys.stdin.readline()) for _ in range(K)]

min_cable_length = 1
max_cable_length = max(cables)

while min_cable_length <= max_cable_length:
    mid_cable_length = (min_cable_length + max_cable_length) // 2

    if sum(map(lambda x: x // mid_cable_length, cables)) >= N:
        min_cable_length = mid_cable_length + 1
    else:
        max_cable_length = mid_cable_length - 1

sys.stdout.write(str(max_cable_length))
