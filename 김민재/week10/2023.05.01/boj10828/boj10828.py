import sys

inputs = sys.stdin.read().splitlines()[1:]

stack = []
result = []
for command in inputs:
    if command.startswith("push"):
        stack.append(command.split()[1])
    elif command == "pop":
        result.append(stack.pop() if stack else "-1")
    elif command == "size":
        result.append(str(len(stack)))
    elif command == "empty":
        result.append('0' if stack else '1')
    elif command == "top":
        result.append(stack[-1] if stack else "-1")

sys.stdout.write('\n'.join(result))
