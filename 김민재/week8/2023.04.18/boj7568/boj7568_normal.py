import sys

size = [list(map(int, x.split())) for x in sys.stdin.read().splitlines()[1:]]
result = [1] * len(size)

for i, person in enumerate(size[:-1]):
    for j, comparison in enumerate(size[i+1:]):
        if person[0] > comparison[0] and person[1] > comparison[1]:
            result[i + j + 1] += 1
        elif person[0] < comparison[0] and person[1] < comparison[1]:
            result[i] += 1

sys.stdout.write(' '.join(map(str, result)))
