import sys
from collections import Counter

N, M = map(int, sys.stdin.readline().split())
trees = Counter(map(int, sys.stdin.readline().split()))

start, end = 0, max(trees)
while start <= end:
    mid = (start + end) // 2
    log = sum((tree_hight - mid) * i for tree_hight, i in trees.items() if tree_hight > mid)

    if log >= M:
        start = mid + 1
    else:
        end = mid - 1

sys.stdout.write(str(end))
