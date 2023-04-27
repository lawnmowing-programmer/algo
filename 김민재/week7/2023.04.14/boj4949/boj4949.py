import sys

inputs = sys.stdin.read().splitlines()[:-1]

BRACKET_MAP = {'(': ')', '[': ']'}

result = []
for line in inputs:
    if line.count('(') != line.count(')') or line.count('[') != line.count(']'):
        result.append("no")
        continue
    stack = []
    is_balanced = True
    for char in line:
        if char in BRACKET_MAP:
            stack.append(char)
        elif char in BRACKET_MAP.values() and stack and BRACKET_MAP[stack.pop()] != char:
            is_balanced = False
            break
    result.append("yes" if is_balanced and not stack else "no")

sys.stdout.write('\n'.join(result))
