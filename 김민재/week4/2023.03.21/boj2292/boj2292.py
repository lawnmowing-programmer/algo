import sys

N = int(sys.stdin.readline()) - 1

count = 1
while N > 0:
    N -= 6 * count
    count += 1

sys.stdout.write(str(count))
