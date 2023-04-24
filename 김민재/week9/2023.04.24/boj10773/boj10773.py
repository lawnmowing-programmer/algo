import sys

inputs = map(int, sys.stdin.read().splitlines()[1:])

stack = []
for money in inputs:
    if money:
        stack.append(money)
    else:
        stack.pop()

sys.stdout.write(str(sum(stack)))
