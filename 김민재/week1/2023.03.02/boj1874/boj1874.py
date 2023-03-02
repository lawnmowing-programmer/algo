import sys

n, *nums = map(int, sys.stdin.buffer.read().splitlines())

count = 1
stack = []
stack_operator = []
for stack_pop_num in nums:
    while count <= stack_pop_num:
        stack.append(count)
        stack_operator.append("+")
        count += 1

    if stack.pop() != stack_pop_num:
        stack_operator.clear()
        break
    stack_operator.append("-")

sys.stdout.write('\n'.join(stack_operator) if stack_operator else "NO")
