import sys

N, M, B = map(int, sys.stdin.readline().split())
landscape = [block for _ in range(N) for block in map(int, sys.stdin.readline().split())]
able_blocks = sum(landscape) + B

min_time = float('inf')
result_height = 0
for height in range(min(landscape), max(landscape) + 1):
    if able_blocks >= height * N * M:
        time = 0
        for block_height in landscape:
            diff = block_height - height
            if diff > 0:
                time += diff * 2
            else:
                time -= diff * 1

        if time <= min_time:
            min_time = time
            result_height = height
    else:
        break

sys.stdout.write(str(min_time) + ' ' + str(result_height))
