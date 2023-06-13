import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
broken = sys.stdin.readline().split() if M else []

result = abs(100 - N)
for num in range(1000001):
    for button in str(num):
        if button in broken:
            break
    else:
        result = min(result, len(str(num)) + abs(num - N))

sys.stdout.write(str(result))
