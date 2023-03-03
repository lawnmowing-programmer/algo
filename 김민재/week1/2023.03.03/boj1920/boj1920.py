import sys

N = sys.stdin.readline()
A = set(sys.stdin.readline().split())
M = sys.stdin.readline()

sys.stdout.write('\n'.join(('1' if num in A else '0') for num in sys.stdin.readline().split()))
