import sys

A, B, V = map(int, sys.stdin.readline().split())

sys.stdout.write(str((V - B - 1) // (A - B) + 1))
