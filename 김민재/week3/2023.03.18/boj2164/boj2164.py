import sys

N = int(sys.stdin.readline())
square = 1

while square < N:
    square *= 2

sys.stdout.write(str(2 * N - square))
