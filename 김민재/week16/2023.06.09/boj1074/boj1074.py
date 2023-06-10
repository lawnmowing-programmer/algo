import sys

N, r, c = map(int, sys.stdin.readline().split())

result = 0
for n in range(N, 0, -1):
    split_point = 2 ** (n - 1)
    if r >= split_point and c >= split_point:
        result += 3 * (split_point ** 2)
        r %= split_point
        c %= split_point
    elif r >= split_point:
        result += 2 * (split_point ** 2)
        r %= split_point
    elif c >= split_point:
        result += split_point ** 2
        c %= split_point

sys.stdout.write(str(result))
