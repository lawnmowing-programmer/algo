import sys

T, *inputs = map(int, sys.stdin.buffer.read().splitlines())

result = []

for k, n in zip(inputs[::2], inputs[1::2]):
    floor = [population for population in range(1, n + 1)]

    for i in range(k):
        for j in range(1, n):
            floor[j] += floor[j - 1]

    result.append(floor[-1])

sys.stdout.write('\n'.join(map(str, result)))
