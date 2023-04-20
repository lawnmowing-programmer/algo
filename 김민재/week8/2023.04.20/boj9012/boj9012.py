import sys

inputs = sys.stdin.read().splitlines()[1:]

result = []
for line in inputs:
    parenthesis_count = 0
    for i, char in enumerate(line):
        if char == '(':
            parenthesis_count += 1
        elif char == ')':
            parenthesis_count -= 1
        if len(line) - 1 - i < parenthesis_count or parenthesis_count < 0:
            break
    result.append("YES" if parenthesis_count == 0 else "NO")

sys.stdout.write('\n'.join(result))
