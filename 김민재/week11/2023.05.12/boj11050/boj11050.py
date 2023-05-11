import sys
from math import comb

N, K = map(int, sys.stdin.readline().split())

sys.stdout.write(str(comb(N, K)))
